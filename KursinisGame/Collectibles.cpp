#include "Collectibles.h"
void Collectibles::initVariables()
{
	this->speedMove = 6.f;
}


Collectibles::Collectibles(sf::Texture* collectibleTexture, float posX, float posY) // konstruktorius
{
	this->initVariables();
	this->collectibleSprite.setTexture(*collectibleTexture);
	this->collectibleSprite.scale(0.7f, 0.7f);
	this->collectibleSprite.setPosition(posX, posY);
}

Collectibles::~Collectibles() // destruktorius
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