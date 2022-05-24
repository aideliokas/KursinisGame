
#pragma once
#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Collectibles
{

private:

	sf::Sprite playerSprite;
	sf::Texture* playerTexture;

	float speedMove;

	void initVariables();
	void initSprite();


public:
	Collectibles();
	virtual ~Collectibles();



	sf::Vector2f getPos();
	sf::FloatRect getBounds();

	void render(sf::RenderTarget& target);

};

