#include "Water.h"

Water::Water(sf::Texture* texture, float width, float height)
{
	this->sprite.setTexture(*texture);
	rect.setSize(sf::Vector2f(width, height));
	rect.setFillColor(sf::Color::Blue);
}

Water::~Water()
{
}
