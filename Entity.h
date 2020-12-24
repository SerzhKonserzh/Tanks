#pragma once
#include "Random.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;

	virtual void render(sf::RenderTarget* target);
private:
protected:

};

