#include "Game.h"

void Game::initializeWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1500, 850), "OSU 2.0", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
	this->mapTextures[PlayerTex] = new sf::Texture();
	this->mapTextures[PlayerTex]->loadFromFile("Textures/Player.png");
	this->mapTextures[PlayerTex1] = new sf::Texture();
	this->mapTextures[PlayerTex1]->loadFromFile("Textures/Player1.png");
	this->mapTextures[PlayerTex1] = new sf::Texture();
	this->mapTextures[PlayerTex1]->loadFromFile("Textures/Player1.png");
	this->mapTextures[Collectible1] = new sf::Texture();
	this->mapTextures[Collectible1]->loadFromFile("Textures/Collectible-1.png");
	this->mapTextures[Collectible2] = new sf::Texture();
	this->mapTextures[Collectible2]->loadFromFile("Textures/Collectible-2.png");
	this->mapTextures[Collectible3] = new sf::Texture();
	this->mapTextures[Collectible3]->loadFromFile("Textures/Collectible-3.png");
	this->mapTextures[Collectible4] = new sf::Texture();
	this->mapTextures[Collectible4]->loadFromFile("Textures/Collectible-4.png");
	this->mapTextures[Background] = new sf::Texture();
	this->mapTextures[Background]->loadFromFile("Textures/back2.jpg");
}
void Game::initPlayer()
{
	this->player = new Player(this->mapTextures[PlayerTex]);
}

void Game::initText()
{
	this->font.loadFromFile("Fonts/HackbotFreeTrial-8MgA2.otf");

	this->text.setFont(this->font);
	this->text.setCharacterSize(30);
	this->text.setFillColor(sf::Color::White);
	this->text.setOutlineColor(sf::Color::Black);
	this->text.setOutlineThickness(1);
	this->text.setString("NONE");
}
void Game::initCollectibles()
{
	this->spawnTimerMax = 500.f;
	this->spawnTimer = this->spawnTimerMax;
}

Game::Game()
{
	this->initializeWindow();
	this->initTextures();
	this->initPlayer();
	this->initCollectibles();
	this->initText();
	this->backSprite.setTexture(*this->mapTextures[Background]);
}


Game::~Game()
{
}

void Game::start()
{
	//Game loop
	while (this->window->isOpen()/*this->running() && !this->endGame */)
	{
		//Update
		this->update();
		//Render
		this->render();
	}
}


void Game::updatePollEvents()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed || e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
		{
			this->window->close();
		}
	}
}
void Game::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
	{
		// Move player
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && this->player->getBounds().left >= 0)
		{
			this->player->move(-2.5f, this->mapTextures[PlayerTex1]);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && this->player->getBounds().left <= 1500 - this->player->getBounds().width)
		{
			this->player->move(2.5f, this->mapTextures[PlayerTex]);
		}
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && this->player->getBounds().left >= 0)
		{
			this->player->move(-1.f, this->mapTextures[PlayerTex1]);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && this->player->getBounds().left <= 1500 - this->player->getBounds().width)
		{
			this->player->move(1.f, this->mapTextures[PlayerTex]);
		}
	}
}

void Game::updateCollectibles()
{
	for (auto coll : vecCollectibles) 
		{
			coll->update();
		}
	this->spawnTimer += rand() % 3 * 1.f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->vecCollectibles.push_back(new Collectibles(this->mapTextures[Collectible1], 150.f, -70.f));
		this->spawnTimer = 0.f;
	}

	
}

void Game::updateText()
{
	std::stringstream ss;
	ss << "SCORE: " << this->score;
	this->text.setString(ss.str());
}

void Game::update()
{
	this->updatePollEvents();
	this->updateInput();
	//this->player->update();
	this->updateCollectibles();
	this->updateText();
}

void Game::render()
{

	this->window->draw(backSprite);

	// Draw all

	this->player->render(*this->window);

	for (auto collectibles : this->vecCollectibles)
	{
		collectibles->render(*this->window);
	}

	this->window->draw(this->text);
	this->window->display();
}

