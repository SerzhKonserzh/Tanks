#pragma once
#include "Entity.h"

class Bullet:
	public Entity
{
public:
	Bullet(sf::Texture* texture,float pos_x,float pos_y,float dir_x,float dir_y,float movement_speed);
	virtual ~Bullet();
	//Variables
	sf::Vector2f direction;
	float counterLifetime = 0.f;
	float Lifetime = 500.f;
	float attackDamage=5.f;
	float movementSpeed;
	bool isDestroyed = false;

	const sf::FloatRect getBounds() const;
	//Functions
	void update();
	void render(sf::RenderTarget* target);
	
};

