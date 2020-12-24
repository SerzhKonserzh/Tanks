#include "Wall.h"

Wall::Wall(sf::Texture* texture, float width, float height)
{
	this->sprite.setTexture(*texture);
	rect.setSize(sf::Vector2f(width, height));
	rect.setFillColor(sf::Color::White);
}

Wall::~Wall()
{
}

void Wall::update()
{
	sprite.setPosition(rect.getPosition());
}
