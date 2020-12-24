#include "Enemy.h"

Enemy::Enemy(sf::Texture* texture, float pos_x, float pos_y, float movement_speed)
{
	this->sprite.setTexture(*texture);
	this->rect.setPosition(pos_x,pos_y);
	this->sprite.setOrigin(50.f,50.f);
	this->movementSpeed = movement_speed;
	this->setHitbox();
}

Enemy::~Enemy()
{

}
void Enemy::setHitbox()
{
		rect.setSize(sf::Vector2f(100.f, 100.f));
		rect.setFillColor(sf::Color::Blue);
		rect.setOrigin(rect.getSize().x / 2, rect.getSize().y / 2);
}

void Enemy::initVariables()
{

}

void Enemy::update()
{
	sprite.setPosition(rect.getPosition());
	updateAttack();
}
void Enemy::updateMovement()
{
	if (aggroed == false)
	{
		if (direction == 1)//Left
		{
			if (canMoveLeft == true)
			{
				//rect.setRotation(0);
				sprite.setRotation(0);
				rect.move(-movementSpeed, 0.f);
				canMoveLeft = true;
				canMoveRight = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		else if (direction == 2)//Right
		{
			if (canMoveRight == true)
			{
				//rect.setRotation(180);
				sprite.setRotation(180);
				rect.move(movementSpeed, 0.f);
				canMoveLeft = true;
				canMoveRight = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		else if (direction == 3)//Up
		{
			if (canMoveUp == true)
			{
				//rect.setRotation(90);
				sprite.setRotation(90);
				rect.move(0.f, -movementSpeed);
				canMoveLeft = true;
				canMoveRight = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		else if (direction == 4)//Down
		{
			if (canMoveDown == true)
			{
				//rect.setRotation(270);
				sprite.setRotation(270);
				rect.move(0.f, movementSpeed);
				canMoveLeft = true;
				canMoveRight = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		counterM++;
		if (counterM >= movementLength)
		{
			direction = generateRandom(10);
			counterM = 0;
		}
	}
	if (aggroed == true)
	{
		if (direction == 1)//Left
		{
			if (canMoveLeft == true)
			{
				//rect.setRotation(0);
				sprite.setRotation(0);
				rect.move(-movementSpeed, 0.f);
				canMoveLeft = true;
				canMoveRight = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		else if (direction == 2)//Right
		{
			if (canMoveRight == true)
			{
				//rect.setRotation(180);
				sprite.setRotation(180);
				rect.move(movementSpeed, 0.f);
				canMoveLeft = true;
				canMoveRight = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		else if (direction == 3)//Up
		{
			if (canMoveUp == true)
			{
				//rect.setRotation(90);
				sprite.setRotation(90);
				rect.move(0.f, -movementSpeed);
				canMoveLeft = true;
				canMoveRight = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		else if (direction == 4)//Down
		{
			if (canMoveDown == true)
			{
				//rect.setRotation(270);
				sprite.setRotation(270);
				rect.move(0.f, movementSpeed);
				canMoveLeft = true;
				canMoveRight = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		counterM++;
		if (counterM >= movementLength)
		{
			counterM = 0;
		}
	}
}
const bool Enemy::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}
void Enemy::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 1.f;
}
void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

