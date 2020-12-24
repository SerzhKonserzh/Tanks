#include "DuoState.h"
#include <cstdlib>

//Initializer functions
void DuoState::initKeybinds()
{
	std::ifstream ifs("config/gamestate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();
}

void DuoState::initFonts()
{
	if (!this->font.loadFromFile("fonts/MachineBT.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void DuoState::initTextures()
{
	if (!this->textures["PLAYER_IDLE"].loadFromFile("images/sprites/tester.png"))
	{
		this->textures["PLAYER_IDLE"].loadFromFile("images/default.jpg");
		//throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	if (!this->textures["BULLET"].loadFromFile("images/bullet.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	if (!this->textures["PLAYER2"].loadFromFile("images/player2.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	if (!this->textures["DEAD"].loadFromFile("images/dead.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	if (!this->textures["WALL"].loadFromFile("images/wall.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	if (!this->textures["WATER"].loadFromFile("images/water.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	if (!this->textures["EARTH"].loadFromFile("images/earth.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	if (!this->textures["CRATE"].loadFromFile("images/crate.jpg"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
}
void DuoState::initBackground()
{
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y))
	);
	this->background.setTexture(&this->textures["EARTH"]);
}


void DuoState::initPauseMenu()
{
	this->pmenu = new PauseMenu(*this->window, this->font);
	this->pmenu->str=L"Quit";
	this->pmenu->addButton("QUIT", 700.f, this->pmenu->str);
}

void DuoState::initPlayers()
{
	player = new Player(200.f, 500.f);
	this->player->sprite.setTexture(this->textures["PLAYER_IDLE"]);
	this->player->sprite.setOrigin(
		this->textures["PLAYER_IDLE"].getSize().x / 2,
		this->textures["PLAYER_IDLE"].getSize().y / 2);
	player2 = new Player(1700.f, 500.f);
	this->player2->sprite.setTexture(this->textures["PLAYER2"]);
	this->player2->sprite.setOrigin(
		this->textures["PLAYER2"].getSize().x / 2,
		this->textures["PLAYER2"].getSize().y / 2);
}

void DuoState::initMap()
{
	int counter = 0;
	while (counter < 20)
	{
		walls.push_back(new Wall(&this->textures["WALL"], 100.f, 100.f));
		walls[counter]->rect.setPosition(counter * 100.f, -75.f);
		walls[counter]->sprite.setPosition(counter * 100.f, -75.f);
		counter++;
	}
	while (counter < 40)
	{
		walls.push_back(new Wall(&this->textures["WALL"], 100.f, 100.f));
		walls[counter]->rect.setPosition((counter - 20) * 100.f, 1025.f);
		walls[counter]->sprite.setPosition((counter - 20) * 100.f, 1025.f);
		counter++;
	}
	while (counter < 55)
	{
		walls.push_back(new Wall(&this->textures["WALL"], 100.f, 100.f));
		walls[counter]->rect.setPosition(-75.f, (counter - 40) * 100.f);
		walls[counter]->sprite.setPosition(-75.f, (counter - 40) * 100.f);
		counter++;
	}
	while (counter < 70)
	{
		walls.push_back(new Wall(&this->textures["WALL"], 100.f, 100.f));
		walls[counter]->rect.setPosition(1895.f, (counter - 55) * 100.f);
		walls[counter]->sprite.setPosition(1895.f, (counter - 55) * 100.f);
		counter++;
	}
	while (counter < 75)
	{
		walls.push_back(new Wall(&this->textures["WALL"], 100.f, 100.f));
		walls[counter]->rect.setPosition(475.f, (counter - 70) * 100.f + 300.f);
		walls[counter]->sprite.setPosition(475.f, (counter - 70) * 100.f + 300.f);
		counter++;
	}
	while (counter < 80)
	{
		walls.push_back(new Wall(&this->textures["WALL"], 100.f, 100.f));
		walls[counter]->rect.setPosition(1300.f, (counter - 75) * 100.f + 300.f);
		walls[counter]->sprite.setPosition(1300.f, (counter - 75) * 100.f + 300.f);
		counter++;
	}
	int counterW = 0;
	while (counterW < 3)
	{
		waters.push_back(new Water(&this->textures["WATER"], 100.f, 100.f));
		waters[counterW]->rect.setPosition(counterW * 100.f + 800.f, 350.f);
		waters[counterW]->sprite.setPosition(counterW * 100.f + 800.f, 350.f);
		counterW++;
	}
	while (counterW < 6)
	{
		waters.push_back(new Water(&this->textures["WATER"], 100.f, 100.f));
		//waters[counterW]->rect.setPosition(counterW * 100.f+300.f, 700.f);
		//waters[counterW]->sprite.setPosition(counterW * 100.f+300.f, 700.f);
		waters[counterW]->rect.setPosition((counterW - 3) * 100.f + 800.f, 450.f);
		waters[counterW]->sprite.setPosition((counterW - 3) * 100.f + 800.f, 450.f);
		counterW++;
	}
	while (counterW < 9)
	{
		waters.push_back(new Water(&this->textures["WATER"], 100.f, 100.f));
		waters[counterW]->rect.setPosition((counterW - 6) * 100.f + 800.f, 550.f);
		waters[counterW]->sprite.setPosition((counterW - 6) * 100.f + 800.f, 550.f);
		counterW++;
	}
	int counterB = 0;
	while (counterB < 2)
	{
		breakables.push_back(new Breakable(&this->textures["CRATE"], 75.f, 75.f));
		breakables[counterB]->rect.setPosition(1000.f, counterB * 75.f+75.f);
		breakables[counterB]->sprite.setPosition(1000.f, counterB * 75.f + 75.f);
		counterB++;
	}
	while (counterB < 4)
	{
		breakables.push_back(new Breakable(&this->textures["CRATE"], 75.f, 75.f));
		breakables[counterB]->rect.setPosition(850.f, (counterB-2) * 75.f + 800.f);
		breakables[counterB]->sprite.setPosition(850.f, (counterB-2) * 75.f + 800.f);
		counterB++;
	}


}

//Constructors/Destructors
DuoState::DuoState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initKeybinds();
	this->initFonts();
	this->initTextures();
	this->initPauseMenu();
	this->initMap();
	this->initPlayers();
	this->initBackground();
}

DuoState::~DuoState()
{
	delete this->pmenu;
	delete this->player;
	delete this->player2;
	for (auto* i : this->bullets)
	{
		delete i;
	}
}

void DuoState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeyTime())
	{
		if (!this->paused)
			this->pauseState();
		else
			this->unpauseState();
	}
}

void DuoState::updatePlayerInput(const float& dt)
{
	//Update player input
	//player->updateMovement();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		if (player->canMoveLeft)
		{
			//this->player->rect.setRotation(-90);
			this->player->sprite.setRotation(-90);
			this->player->rect.move(-this->player->movementSpeed, 0.f);
			dir_x = -1.f;
			dir_y = 0.f;
			this->player->direction = 1;
			this->player->canMoveLeft = true;
			this->player->canMoveRight = true;
			this->player->canMoveUp = true;
			this->player->canMoveDown = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		if (player->canMoveRight)
		{
			//this->player->rect.setRotation(90);
			this->player->sprite.setRotation(90);
			this->player->rect.move(this->player->movementSpeed, 0.f);
			dir_x = 1.f;
			dir_y = 0.f;
			this->player->direction = 2;
			this->player->canMoveLeft = true;
			this->player->canMoveRight = true;
			this->player->canMoveUp = true;
			this->player->canMoveDown = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		if (player->canMoveUp)
		{
			//this->player->rect.setRotation(0);
			this->player->sprite.setRotation(0);
			this->player->rect.move(0.f, -this->player->movementSpeed);
			dir_y = -1.f;
			dir_x = 0.f;
			this->player->direction = 3;
			this->player->canMoveLeft = true;
			this->player->canMoveRight = true;
			this->player->canMoveUp = true;
			this->player->canMoveDown = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		if (player->canMoveDown)
		{
			//this->player->rect.setRotation(180);
			this->player->sprite.setRotation(180);
			this->player->rect.move(0.f, this->player->movementSpeed);
			dir_y = 1.f;
			dir_x = 0.f;
			this->player->direction = 4;
			this->player->canMoveLeft = true;
			this->player->canMoveRight = true;
			this->player->canMoveUp = true;
			this->player->canMoveDown = true;
		}
	}
	else
	{

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("FIRE"))) && this->player->canAttack())
	{
		this->bullets.push_back(new Bullet(&this->textures["BULLET"], this->player->rect.getPosition().x, this->player->rect.getPosition().y, dir_x, dir_y, 5.f));
	}
	//Player 2
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		if (player2->canMoveLeft)
		{
			//this->player->rect.setRotation(-90);
			this->player2->sprite.setRotation(-90);
			this->player2->rect.move(-this->player2->movementSpeed, 0.f);
			dir_x2 = -1.f;
			dir_y2 = 0.f;
			this->player2->direction = 1;
			this->player2->canMoveLeft = true;
			this->player2->canMoveRight = true;
			this->player2->canMoveUp = true;
			this->player2->canMoveDown = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		if (player2->canMoveRight)
		{
			//this->player->rect.setRotation(90);
			this->player2->sprite.setRotation(90);
			this->player2->rect.move(this->player2->movementSpeed, 0.f);
			dir_x2 = 1.f;
			dir_y2 = 0.f;
			this->player2->direction = 2;
			this->player2->canMoveLeft = true;
			this->player2->canMoveRight = true;
			this->player2->canMoveUp = true;
			this->player2->canMoveDown = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		if (player2->canMoveUp)
		{
			//this->player->rect.setRotation(0);
			this->player2->sprite.setRotation(0);
			this->player2->rect.move(0.f, -this->player2->movementSpeed);
			dir_y2 = -1.f;
			dir_x2 = 0.f;
			this->player2->direction = 3;
			this->player2->canMoveLeft = true;
			this->player2->canMoveRight = true;
			this->player2->canMoveUp = true;
			this->player2->canMoveDown = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		if (player2->canMoveDown)
		{
			//this->player->rect.setRotation(180);
			this->player2->sprite.setRotation(180);
			this->player2->rect.move(0.f, this->player2->movementSpeed);
			dir_y2 = 1.f;
			dir_x2 = 0.f;
			this->player2->direction = 4;
			this->player2->canMoveLeft = true;
			this->player2->canMoveRight = true;
			this->player2->canMoveUp = true;
			this->player2->canMoveDown = true;
		}
	}
	else
	{

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("FIRE2"))) && this->player2->canAttack())
	{
		this->bullets2.push_back(new Bullet(&this->textures["BULLET"], this->player2->rect.getPosition().x, this->player2->rect.getPosition().y, dir_x2, dir_y2, 5.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("SPAWN"))) && this->canSpawn())
	{
		this->enemies.push_back(new Enemy(&this->textures["ENEMY"], 1700.f - generateRandom0(2) * 200.f, generateRandom(4) * 200.f, 1.5));
	}
}

void DuoState::updatePauseButtons()
{
	if (this->pmenu->isButtonPressed("QUIT"))
		this->endState();
}

void DuoState::updateBullets()
{
	//unsigned counter = 0;
	//for (auto* bullet : this->bullets)
	//{
	//	bullet->update();
	//	//bullet culling(top of screen)
	//	if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
	//	{
	//		//Delete bullet
	//		delete this->bullets.at(counter);
	//		this->bullets.erase(this->bullets.begin()+counter);
	//		--counter;
	//	}
	//	if (bullet->getBounds().left + bullet->getBounds().width < 0.f)
	//	{
	//		//Delete bullet
	//		delete this->bullets.at(counter);
	//		this->bullets.erase(this->bullets.begin() + counter);
	//		--counter;
	//	}
	//	//if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
	//	//{
	//	//	//Delete bullet
	//	//	delete this->bullets.at(counter);
	//	//	this->bullets.erase(this->bullets.begin() + counter);
	//	//	--counter;
	//	//}
	//	//if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
	//	//{
	//	//	//Delete bullet
	//	//	delete this->bullets.at(counter);
	//	//	this->bullets.erase(this->bullets.begin() + counter);
	//	//	--counter;
	//	//}
	//	++counter;
	//}
}

void DuoState::updateEnemySpawn()
{
	if (this->spawnCooldown < this->spawnCooldownMax)
		this->spawnCooldown += 1.f;
}

void DuoState::updateMap()
{
	for (int w = 0; w < walls.size(); w++)
	{
		//window->draw(walls[w]->rect);
		window->draw(walls[w]->sprite);
	}
	for (int w = 0; w < waters.size(); w++)
	{
		//window->draw(waters[w]->rect);
		window->draw(waters[w]->sprite);
	}
	for (int b = 0; b < breakables.size(); b++)
	{
		//window->draw(waters[w]->rect);
		window->draw(breakables[b]->sprite);
	}
}

const bool DuoState::canSpawn()
{
	if (this->spawnCooldown >= this->spawnCooldownMax)
	{
		this->spawnCooldown = 0.f;
		return true;
	}
	return false;
}

void DuoState::collision()
{
	//Destroying bullets
	for (int i = 0; i < this->bullets.size(); i++)
	{
		if (this->bullets[i]->isDestroyed == true)
		{
			this->bullets.erase(this->bullets.begin() + i);
			break;
		}
	}	
	for (int i = 0; i < this->bullets2.size(); i++)
	{
		if (this->bullets2[i]->isDestroyed == true)
		{
			this->bullets2.erase(this->bullets2.begin() + i);
			break;
		}
	}
	//ram attack
	for (int k = 0; k < enemies.size(); k++)
	{
		if (player->rect.getGlobalBounds().intersects(enemies[k]->rect.getGlobalBounds()))
		{
			if (player->isAlive)
			{
				player->hp -= enemies[k]->RAMattack;
				enemies[k]->alive = false;
			}
		}

	}
	//player collides the wall
	for (int w = 0; w < walls.size(); w++)
	{
		if (player->rect.getGlobalBounds().intersects(walls[w]->rect.getGlobalBounds()))
		{
			if (player->direction == 1)//left
			{
				player->canMoveLeft = false;
				player->rect.move(1.f, 0.f);
			}
			else if (player->direction == 2)//right
			{
				player->canMoveRight = false;
				player->rect.move(-1.f, 0.f);
			}
			else if (player->direction == 3)//up
			{
				player->canMoveUp = false;
				player->rect.move(0.f, 1.f);
			}
			else if (player->direction == 4)//down
			{
				player->canMoveDown = false;
				player->rect.move(0.f, -1.f);
			}
			else
			{

			}
		}
		if (player2->rect.getGlobalBounds().intersects(walls[w]->rect.getGlobalBounds()))
		{
			if (player2->direction == 1)//left
			{
				player2->canMoveLeft = false;
				player2->rect.move(1.f, 0.f);
			}
			else if (player2->direction == 2)//right
			{
				player2->canMoveRight = false;
				player2->rect.move(-1.f, 0.f);
			}
			else if (player2->direction == 3)//up
			{
				player2->canMoveUp = false;
				player2->rect.move(0.f, 1.f);
			}
			else if (player2->direction == 4)//down
			{
				player2->canMoveDown = false;
				player2->rect.move(0.f, -1.f);
			}
			else
			{

			}
		}
	}	
	//player collides the player2
		if (player->rect.getGlobalBounds().intersects(player2->rect.getGlobalBounds()))
		{
			if (player->direction == 1)//left
			{
				player->canMoveLeft = false;
				player->rect.move(1.f, 0.f);
			}
			else if (player->direction == 2)//right
			{
				player->canMoveRight = false;
				player->rect.move(-1.f, 0.f);
			}
			else if (player->direction == 3)//up
			{
				player->canMoveUp = false;
				player->rect.move(0.f, 1.f);
			}
			else if (player->direction == 4)//down
			{
				player->canMoveDown = false;
				player->rect.move(0.f, -1.f);
			}
			else
			{

			}
		
		}
	//player2 collides the player
		if (player2->rect.getGlobalBounds().intersects(player->rect.getGlobalBounds()))
		{
			if (player2->direction == 1)//left
			{
				player2->canMoveLeft = false;
				player2->rect.move(1.f, 0.f);
			}
			else if (player2->direction == 2)//right
			{
				player2->canMoveRight = false;
				player2->rect.move(-1.f, 0.f);
			}
			else if (player2->direction == 3)//up
			{
				player2->canMoveUp = false;
				player2->rect.move(0.f, 1.f);
			}
			else if (player2->direction == 4)//down
			{
				player2->canMoveDown = false;
				player2->rect.move(0.f, -1.f);
			}
			else
			{

			}

		}
	//bullet collides the wall
	for (int w = 0; w < this->walls.size(); ++w)
	{
		for (size_t i = 0; i < this->bullets.size(); i++)
		{
			if (this->bullets[i]->rect.getGlobalBounds().intersects(this->walls[w]->rect.getGlobalBounds()))
			{
				this->bullets[i]->isDestroyed = true;
				if (this->bullets[i]->isDestroyed == true)
				{
					this->bullets.erase(this->bullets.begin() + i);
				}

				//this->enemies.erase(this->enemies.begin() + k);
			}
		}		
		for (size_t i = 0; i < this->bullets2.size(); i++)
		{
			if (this->bullets2[i]->rect.getGlobalBounds().intersects(this->walls[w]->rect.getGlobalBounds()))
			{
				this->bullets2[i]->isDestroyed = true;
				if (this->bullets2[i]->isDestroyed == true)
				{
					this->bullets2.erase(this->bullets2.begin() + i);
				}

				//this->enemies.erase(this->enemies.begin() + k);
			}
		}
	}
	//player collides the water
	for (int w = 0; w < waters.size(); w++)
	{
		if (player->rect.getGlobalBounds().intersects(waters[w]->rect.getGlobalBounds()))
		{
			if (player->direction == 1)//left
			{
				player->canMoveLeft = false;
				player->rect.move(1.f, 0.f);
			}
			else if (player->direction == 2)//right
			{
				player->canMoveRight = false;
				player->rect.move(-1.f, 0.f);
			}
			else if (player->direction == 3)//up
			{
				player->canMoveUp = false;
				player->rect.move(0.f, 1.f);
			}
			else if (player->direction == 4)//down
			{
				player->canMoveDown = false;
				player->rect.move(0.f, -1.f);
			}
			else
			{

			}
		}
		if (player2->rect.getGlobalBounds().intersects(waters[w]->rect.getGlobalBounds()))
		{
			if (player2->direction == 1)//left
			{
				player2->canMoveLeft = false;
				player2->rect.move(1.f, 0.f);
			}
			else if (player2->direction == 2)//right
			{
				player2->canMoveRight = false;
				player2->rect.move(-1.f, 0.f);
			}
			else if (player2->direction == 3)//up
			{
				player2->canMoveUp = false;
				player2->rect.move(0.f, 1.f);
			}
			else if (player2->direction == 4)//down
			{
				player2->canMoveDown = false;
				player2->rect.move(0.f, -1.f);
			}
			else
			{

			}
		}
	}
	//Player collides with crate
	for (int b = 0; b < breakables.size(); b++)
	{
		if (player->rect.getGlobalBounds().intersects(breakables[b]->rect.getGlobalBounds()))
		{
			if (player->direction == 1)//left
			{
				player->canMoveLeft = false;
				player->rect.move(1.f, 0.f);
			}
			else if (player->direction == 2)//right
			{
				player->canMoveRight = false;
				player->rect.move(-1.f, 0.f);
			}
			else if (player->direction == 3)//up
			{
				player->canMoveUp = false;
				player->rect.move(0.f, 1.f);
			}
			else if (player->direction == 4)//down
			{
				player->canMoveDown = false;
				player->rect.move(0.f, -1.f);
			}
			else
			{

			}
		}
		if (player2->rect.getGlobalBounds().intersects(breakables[b]->rect.getGlobalBounds()))
		{
			if (player2->direction == 1)//left
			{
				player2->canMoveLeft = false;
				player2->rect.move(1.f, 0.f);
			}
			else if (player2->direction == 2)//right
			{
				player2->canMoveRight = false;
				player2->rect.move(-1.f, 0.f);
			}
			else if (player2->direction == 3)//up
			{
				player2->canMoveUp = false;
				player2->rect.move(0.f, 1.f);
			}
			else if (player2->direction == 4)//down
			{
				player2->canMoveDown = false;
				player2->rect.move(0.f, -1.f);
			}
			else
			{

			}
		}
	}
	//bullet collides the crate
	for (int b = 0; b < this->breakables.size(); ++b)
	{
		for (size_t i = 0; i < this->bullets.size(); i++)
		{
			if (this->bullets[i]->rect.getGlobalBounds().intersects(this->breakables[b]->rect.getGlobalBounds()))
			{
				this->bullets[i]->isDestroyed = true;
				this->breakables[b]->isDestroyed = true;
				if (this->bullets[i]->isDestroyed == true)
				{
					this->bullets.erase(this->bullets.begin() + i);
				}
				if (this->breakables[b]->isDestroyed == true)
				{
					this->breakables.erase(this->breakables.begin() + b);
				}

				//this->enemies.erase(this->enemies.begin() + k);
			}
		}
		for (size_t i = 0; i < this->bullets2.size(); i++)
		{
			if (this->bullets2[i]->rect.getGlobalBounds().intersects(this->breakables[b]->rect.getGlobalBounds()))
			{
				this->bullets2[i]->isDestroyed = true;
				this->breakables[b]->isDestroyed = true;
				if (this->bullets2[i]->isDestroyed == true)
				{
					this->bullets2.erase(this->bullets2.begin() + i);
				}
				if (this->breakables[b]->isDestroyed == true)
				{
					this->breakables.erase(this->breakables.begin() + b);
				}

				//this->enemies.erase(this->enemies.begin() + k);
			}
		}
	}
	//Player bullets
	for (size_t i = 0; i < this->bullets.size(); i++)
	{
		if (this->bullets[i]->rect.getGlobalBounds().intersects(this->player2->rect.getGlobalBounds()))
		{
			this->bullets[i]->isDestroyed = true;
			player2->hp -= bullets[i]->attackDamage;
			if (player2->hp <= 0)
			{
				player2->isAlive = false;
			}
			if (this->bullets[i]->isDestroyed == true)
			{
				this->bullets.erase(this->bullets.begin() + i);
			}

			//this->enemies.erase(this->enemies.begin() + k);
		}
	}
	//Player2 bullets
	for (size_t i = 0; i < this->bullets2.size(); i++)
	{
		if (this->bullets2[i]->rect.getGlobalBounds().intersects(this->player->rect.getGlobalBounds()))
		{
			this->bullets2[i]->isDestroyed = true;
			player->hp -= bullets2[i]->attackDamage;
			if (player->hp <= 0)
			{
				player->isAlive = false;
			}
			if (this->bullets2[i]->isDestroyed == true)
			{
				this->bullets2.erase(this->bullets2.begin() + i);
			}

			//this->enemies.erase(this->enemies.begin() + k);
		}
	}
}
void DuoState::initText(std::string str, float x, float y)
{
	this->DuoText.setFont(font);
	this->DuoText.setFillColor(sf::Color::Red);
	this->DuoText.setCharacterSize(70);
	this->DuoText.setString(str);
	this->DuoText.setPosition(x, y);
}
void DuoState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateKeyTime(dt);
	this->updateInput(dt);

	if (!this->paused) //Unpaused update
	{
		if (this->player->isAlive == true && this->player2->isAlive == true)
		{
			this->updatePlayerInput(dt);
			//this->updateBullets();
			this->player->update(dt);
			this->player2->update(dt);
			this->collision();		
			for (int i = 0; i < this->bullets.size(); i++)
		{
			bullets[i]->update();
		}
		for (int e = 0; e < this->bullets2.size(); e++)
		{
			bullets2[e]->update();
		}
		}
		if (this->player->isAlive == false)
		{
			this->player->sprite.setTexture(this->textures["DEAD"]);
			initText("RED PLAYER WINS",700, 450);

		}
		if (this->player2->isAlive == false)
		{
			this->player2->sprite.setTexture(this->textures["DEAD"]);
			initText("BLUE PLAYER WINS",700, 450);
		}
	
	}
	else //Paused update
	{
		this->pmenu->update(this->mousePosView);
		this->updatePauseButtons();
	}
}

void DuoState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(this->background);
	this->updateMap();
	this->player->render(target);
	this->player2->render(target);
	//bullet.render(target);
	for (int k = 0; k < enemies.size(); k++)
	{
		target->draw(enemies[k]->sprite);
		//target->draw(enemies[k]->rect);
	}
	for (int i = 0; i < bullets.size(); i++)
	{
		target->draw(bullets[i]->sprite);
		//target->draw(bullets[i]->rect);
	}
	for (int e = 0; e < bullets2.size(); e++)
	{
		target->draw(bullets2[e]->sprite);
		//target->draw(bullets[i]->rect);
	}
	if (!this->paused) //pause menu render
	{
		target->draw(this->DuoText);
	}
	if (this->paused) //pause menu render
	{
		this->pmenu->render(*target);
	}

}