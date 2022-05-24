
#pragma once
#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Collectibles
{

private:

	sf::Sprite collectibleSprite;
	sf::Texture* collectibleTexture;

	float speedMove;

	void initVariables();


public:
	Collectibles(sf::Texture* collectibleTexture, float posX, float posY);
	virtual ~Collectibles();



	sf::Vector2f getPos();
	sf::FloatRect getBounds();

	void update();
	void render(sf::RenderTarget& target);

};

