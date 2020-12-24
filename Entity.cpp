#include "Entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
	//target->draw(this->rect);
}
