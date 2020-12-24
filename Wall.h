#pragma once
#include "Enemy.h"
class Wall:
	public Entity
{
public:
	Wall(sf::Texture* texture, float width, float height);
	~Wall();
	void update();
};

