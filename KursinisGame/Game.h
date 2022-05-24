#pragma once
#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <sstream>
#include <vector>
#include <map>

#include "Player.h"
#include "Collectibles.h"

class Game
{


private:

	sf::RenderWindow* window;
	sf::Sprite backSprite;

	enum Textures
	{
		PlayerTex, PlayerTex1, Collectible1, Collectible2,
		Collectible3, Collectible4, Background
	};


	std::map<Textures, sf::Texture*> mapTextures;
	std::vector<Collectibles*> vecCollectibles;
	float spawnTimer;
	float spawnTimerMax;
	int score;
	bool collectiblesRemoved;

	float posX;


	sf::Font font;
	sf::Text text;

	Player* player;

	void initializeWindow();
	void initTextures();
	void initPlayer();
	void initCollectibles();
	void initText();
public:


	Game();
	virtual ~Game();

	void start();

	void updatePollEvents();
	void updateInput();
	void updateCollectibles();

	void updateText();

	void update();
	void render();

};

