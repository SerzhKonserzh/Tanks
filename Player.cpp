#include "Player.h"

//Initializer functions

//Constructors/Destructors
Player::Player(float x, float y)
{
	rect.setSize(sf::Vector2f(100.f, 100.f));
	rect.setFillColor(sf::Color::Blue);
	rect.setOrigin(rect.getSize().x / 2, rect.getSize().y / 2);
	rect.setPosition(x, y);
	initVariables();
}

Player::~Player()
{
}

void Player::setHitbox()
{	
	rect.setSize(sf::Vector2f(100.f, 100.f));
	rect.setFillColor(sf::Color::Blue);
	rect.setOrigin(rect.getSize().x / 2, rect.getSize().y / 2);
	rect.setPosition(200.f, 200.f);
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void Player::initVariables()
{
	this->movementSpeed = 2.f;
	this->attackCooldownMax = 150.f;
	this->attackCooldown = this->attackCooldownMax;
	this->isAlive = true;
}

void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 1.f;
}

void Player::update(const float& dt)
{
	sprite.setPosition(rect.getPosition());
	this->updateAttack();
	if (this->hp <= 0)
	{
		this->isAlive = false;
	}

}

void Player::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		rect.setRotation(-90);
		sprite.setRotation(-90);
		rect.move(-movementSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		rect.setRotation(90);
		sprite.setRotation(90);
		rect.move(movementSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		rect.setRotation(0);
		sprite.setRotation(0);
		rect.move(0.f, -movementSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		rect.setRotation(180);
		sprite.setRotation(180);
		rect.move(0.f, movementSpeed);
	}
}


