#pragma once
#include "Water.h"
class Breakable :
	public Entity
{
public:
	Breakable(sf::Texture* texture, float width, float height);
	virtual ~Breakable();
	bool isDestroyed = false;
	void update();
};

