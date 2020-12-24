#pragma once
#include "Player.h"
class Enemy:
	public Entity
{

public:
	Enemy(sf::Texture* texture, float pos_x, float pos_y,  float movement_speed);
	virtual ~Enemy();
	/*int hp;
	int hpMax;
	int damage;
	int points;*/
	float movementSpeed;
	int direction = 0;
	int counterM = 0;
	float hp = 15.f;
	float RAMattack = 7.f;
	bool alive = true;
	float movementLength=60.f;
	float attackCooldown=250.f;
	float attackCooldownMax=250.f;
	bool canMoveUp = true;
	bool canMoveDown = true;
	bool canMoveLeft = true;
	bool canMoveRight = true;
	bool aggroed = false;

	const bool canAttack();
	void updateAttack();
	void setHitbox();
	void initVariables();
	void update();
	void updateMovement();
	void render(sf::RenderTarget* target);

};

