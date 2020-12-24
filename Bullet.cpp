#include "Bullet.h"
#include <vector>


Bullet::Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
	
	this->sprite.setTexture(*texture);
	this->sprite.setOrigin(20.f, 10.f);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_speed;
	rect.setSize(sf::Vector2f(40.f, 20.f));
	rect.setFillColor(sf::Color::Blue);
	rect.setOrigin(rect.getSize().x / 2, rect.getSize().y / 2);
	if (dir_x == 1.f)
	{
		sprite.setRotation(0);
		rect.setRotation(0);
		this->rect.setPosition(pos_x+50.f, pos_y);
	}
	if (dir_x == -1.f)
	{
		sprite.setRotation(180);
		rect.setRotation(180);
		this->rect.setPosition(pos_x - 50.f, pos_y);
	}
	if (dir_y == 1.f)
	{
		sprite.setRotation(+90);
		rect.setRotation(+90);
		this->rect.setPosition(pos_x , pos_y+ 50.f);
	}
	if (dir_y == -1.f)
	{
		sprite.setRotation(-90);
		rect.setRotation(-90);
		this->rect.setPosition(pos_x , pos_y- 50.f);
	}
}

Bullet::~Bullet()
{

}

const sf::FloatRect Bullet::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Bullet::update()
{
	this->rect.move(this->movementSpeed * this->direction);
	sprite.setPosition(rect.getPosition());
	counterLifetime++;
	if (counterLifetime >= Lifetime)
	{
		isDestroyed = true;
		counterLifetime = 0;
	}
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
