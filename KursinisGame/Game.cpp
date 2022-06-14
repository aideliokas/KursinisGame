#include "Game.h"

void Game::initializeWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1500, 850), "CATCH A CIRCLE!", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
	this->mapTextures[PlayerTex] = new sf::Texture();
	this->mapTextures[PlayerTex]->loadFromFile("Textures/Player.png");
	this->mapTextures[PlayerTex1] = new sf::Texture();
	this->mapTextures[PlayerTex1]->loadFromFile("Textures/Player1.png");
	this->mapTextures[PlayerTex2] = new sf::Texture();
	this->mapTextures[PlayerTex2]->loadFromFile("Textures/Player2.png");
	this->mapTextures[PlayerTex3] = new sf::Texture();
	this->mapTextures[PlayerTex3]->loadFromFile("Textures/Player3.png");
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
	this->font.loadFromFile("Fonts/Shotgun.ttf");

	this->text.setFont(this->font);
	this->text.setCharacterSize(50);
	this->text.setFillColor(sf::Color::Color(241, 233, 210));
	this->text.setOutlineColor(sf::Color::Color(226,62,113));
	this->text.setOutlineThickness(1);
	this->text.setString("NONE");
	this->text.setPosition(700.f, 200.f);

	this->text1.setFont(this->font);
	this->text1.setCharacterSize(30);
	this->text1.setFillColor(sf::Color::Color(241, 233, 210));
	this->text1.setOutlineColor(sf::Color::Color(0, 102, 0));
	this->text1.setOutlineThickness(1);
	this->text1.setString("NONE");
	this->text1.setPosition(720.f, 260.f);

	this->levelText.setFont(this->font);
	this->levelText.setCharacterSize(30);
	this->levelText.setFillColor(sf::Color::Color(241, 233, 210));
	this->levelText.setOutlineColor(sf::Color::Color(0, 102, 0));
	this->levelText.setOutlineThickness(1);
	this->levelText.setString("NONE");
	//this->levelText.setPosition(720.f, 260.f);

	this->text2.setFont(this->font);
	this->text2.setCharacterSize(30);
	this->text2.setFillColor(sf::Color::Color(241, 233, 210));
	this->text2.setOutlineColor(sf::Color::Color(241, 233, 210));
	this->text2.setOutlineThickness(1);
	this->text2.setString("NONE");
	this->text2.setPosition(720.f, 320.f);
}
void Game::initCollectibles()
{
	this->spawnTimerMax = 30.f;
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
	this->posX = 760.f;
}


Game::~Game() // destruktorius naikinantis dinaminius atminties darinius
{
	delete this->window;
	delete this->player;

	for (auto coll : this->vecCollectibles)
	{
		delete coll;
	}
	for (auto& texture : this->mapTextures)
	{
		delete texture.second;
	}
}

void Game::start()
{
	//Game loop
	while (this->window->isOpen())
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
		// Zaidejo judejimo sistema
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && this->player->getBounds().left >= 0)
		{
			this->player->move(-2.f, this->mapTextures[PlayerTex3]);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && this->player->getBounds().left <= 1500 - this->player->getBounds().width)
		{
			this->player->move(2.f, this->mapTextures[PlayerTex2]);
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


	this->spawnTimer += rand() % 2 * 3.f;
	if (this->spawnTimer >= this->spawnTimerMax) 
	{
		if (rand() % 2 && this->posX >=230)
		{
			this->posX -= rand() % 10 * 25; // collectibles kritimo algoritmas
		}
		else if(this->posX <=1500-280)
		{
			this->posX += rand() % 10 * 25;
		}

	    if (this->score >= 300 && this->score < 1000)
		{
			this->speed = 8.f;
		}
		else if (this->score >= 1000)
		{
			this->speed = 10.f;
			
		}
		else
		{
			this->speed = 6.f;
			
		}

		switch (rand() % 5) {
		case 0:
			this->vecCollectibles.push_back(new Collectibles(this->mapTextures[Collectible1], this->posX, -70.f, this->speed));
			break;
		case 1:
			this->vecCollectibles.push_back(new Collectibles(this->mapTextures[Collectible2], this->posX, -70.f, this->speed));
			break;
		case 2:
			this->vecCollectibles.push_back(new Collectibles(this->mapTextures[Collectible3], this->posX, -70.f, this->speed));
			break;
		case 3:
			this->vecCollectibles.push_back(new Collectibles(this->mapTextures[Collectible4], this->posX, -70.f, this->speed));
			break;
		default:
			std::cout << "Gap!\n";
		}
		this->spawnTimer = 0.f;
	}


	this->collectiblesRemoved = false;
	for (int i = 0; i < this->vecCollectibles.size() && !this->collectiblesRemoved; i++)
		{
			if (this->player->getBounds().intersects(this->vecCollectibles[i]->getBounds()))
			{
				this->vecCollectibles.erase(this->vecCollectibles.begin() + i);
				score += 3;
				collected += 1;
				this->collectiblesRemoved = true;
			}
			else if (this->vecCollectibles[i]->getPos().y >= 850) 
			{
				this->vecCollectibles.erase(this->vecCollectibles.begin() + i);
				score -= 10;
				missed += 1;
				this->collectiblesRemoved = true;
			}
		}
	//std::cout << score << "\n";


	
}

void Game::updateText()
{
	std::stringstream ss;
	std::stringstream _collected;
	std::stringstream _missed;
	std::stringstream _levelis;
	ss << this->score;
	_collected << this->collected;
	_missed << this->missed;
	this->text.setString(ss.str());
	this->text1.setString(_collected.str());
	this->text2.setString(_missed.str());

	if(score<300)
	{
		
		_levelis << "LEVEL 1";
	}
	else if (this->score >= 300 && this->score < 1000)
	{
		_levelis << "LEVEL 2";
	}
	else if (this->score >= 1000)
	{
		
		_levelis << "LEVEL 3";
	}
	

	this->levelText.setString(_levelis.str());
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
	this->window->draw(this->text);
	this->window->draw(this->text1);
	this->window->draw(this->levelText);
	//this->window->draw(this->text2);


	this->player->render(*this->window);


	for (auto collectibles : this->vecCollectibles)
	{
		collectibles->render(*this->window);
	}

	
	this->window->display();
}

