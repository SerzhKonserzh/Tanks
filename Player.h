#pragma once

#include "Entity.h"
class Player :
	public Entity
{
private:
public:
	Player(float x, float y);
	virtual ~Player();
	//Variables
	float movementSpeed;
	float hp=20.f;
	float attackCooldown;
	float attackCooldownMax;
	int direction = 0;
	bool isAlive;
	bool canMoveUp = true;
	bool canMoveDown = true;
	bool canMoveLeft = true;
	bool canMoveRight = true;

	//Initializer functions
	void setHitbox();
	//Functions
	const bool canAttack();
	void initVariables();
	void updateAttack();
	void update(const float& dt);
	void updateMovement();
};

