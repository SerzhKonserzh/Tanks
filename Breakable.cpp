#include "Breakable.h"

Breakable::Breakable(sf::Texture* texture,float width,float height)
{
	this->sprite.setTexture(*texture);
	rect.setSize(sf::Vector2f(width, height));
	rect.setFillColor(sf::Color::White);
}

Breakable::~Breakable()
{

}
void Breakable::update()
{
	sprite.setPosition(rect.getPosition());
}