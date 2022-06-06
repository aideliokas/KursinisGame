#pragma once

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>


class Player
{
private:
	sf::Sprite playerSprite;
	sf::Texture* playerTexture;

	float speedMove;

	void initVariables();
	void initSprite();
	//void update();

public:

	Player(sf::Texture* playerTexture); // konstruktorius
	virtual ~Player(); // virtual destruktorius

	sf::Vector2f getPos();
	sf::FloatRect getBounds();

	void move(const float dirX, sf::Texture* playerTexture);
	void render(sf::RenderTarget& target);
};

