#include "Collectibles.h"
void Collectibles::initVariables()
{
	this->speedMove = 1.f;
}
void Collectibles::initSprite()
{
	// Give texture to sprite
	this->playerSprite.setPosition(375, 900);
	// Resize te sprite
	this->playerSprite.scale(1.f, 1.f);
}
sf::Vector2f Collectibles::getPos()
{
	return this->playerSprite.getPosition();
}

sf::FloatRect Collectibles::getBounds()
{
	return this->playerSprite.getGlobalBounds();
}

void Collectibles::render(sf::RenderTarget& target)
{
	target.draw(this->playerSprite);
}