#include "Player.h"



void Player::initVariables()
{
	this->speedMove = 4.5f;
}
void Player::initSprite()
{
	// Give texture to sprite
	
	// Resize te sprite
	this->playerSprite.scale(0.9f, 0.9f);
	this->playerSprite.setPosition(750-this->playerSprite.getGlobalBounds().width/2, 850- this->playerSprite.getGlobalBounds().height);
}

Player::Player(sf::Texture* playerTexture)
{
	this->initVariables();
	this->playerSprite.setTexture(*playerTexture);
	this->initSprite();
}

Player::~Player()
{
}

sf::Vector2f Player::getPos()
{
	return this->playerSprite.getPosition();
}

sf::FloatRect Player::getBounds()
{
	return this->playerSprite.getGlobalBounds();
}

void Player::move(const float dirX, sf::Texture* playerTexture)
{
	this->playerSprite.setTexture(*playerTexture);
	this->playerSprite.move(this->speedMove * dirX, 0.f);
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->playerSprite);
}
