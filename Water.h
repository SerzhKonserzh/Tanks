#pragma once
#include "Wall.h"
class Water :
	public Entity
{
public:
	Water(sf::Texture* texture, float width, float height);
	virtual ~Water();
};

