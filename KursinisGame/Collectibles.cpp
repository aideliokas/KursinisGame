#include "Collectibles.h"
void Collectibles::initVariables()
{
	this->speedMove = 1.f;
}


Collectibles::Collectibles(sf::Texture* collectibleTexture, float posX, float posY)
{
	this->initVariables();
	this->collectibleSprite.setTexture(*collectibleTexture);
	this->collectibleSprite.scale(1.f, 1.f);
	this->collectibleSprite.setPosition(posX, posY);
}

Collectibles::~Collectibles()
{
}





sf::Vector2f Collectibles::getPos()
{
	return this->collectibleSprite.getPosition();
}

sf::FloatRect Collectibles::getBounds()
{
	return this->collectibleSprite.getGlobalBounds();
}

void Collectibles::update()
{
	this->collectibleSprite.move(0.f, this->speedMove);
}

void Collectibles::render(sf::RenderTarget& target)
{
	target.draw(this->collectibleSprite);
}