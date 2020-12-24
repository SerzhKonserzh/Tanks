#include "GameState.h"
#include <cstdlib>

//Initializer functions
void GameState::initKeybinds()
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

void GameState::initFonts()
{
	if (!this->font.loadFromFile("fonts/MachineBT.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void GameState::initTextures()
{
	if (!this->textures["PLAYER_IDLE"].loadFromFile("images/tester.png"))
	{
		this->textures["PLAYER_IDLE"].loadFromFile("images/default.jpg");
		//throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	if (!this->textures["BULLET"].loadFromFile("images/bullet.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	if (!this->textures["ENEMY"].loadFromFile("images/enemy.png"))
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
void GameState::initBackground()
{
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y))
	);
	this->background.setTexture(&this->textures["EARTH"]);
}


void GameState::initPauseMenu()
{
	this->pmenu = new PauseMenu(*this->window, this->font);
	this->pmenu->str = L"Quit";
	this->pmenu->addButton("QUIT", 700.f, this->pmenu->str);
}

void GameState::initPlayers()
{
	player = new Player(200.f,200.f);
	this->player->sprite.setTexture(this->textures["PLAYER_IDLE"]);
	this->player->sprite.setOrigin(
		this->textures["PLAYER_IDLE"].getSize().x / 2,
		this->textures["PLAYER_IDLE"].getSize().y / 2);
}

void GameState::initMap()
{
	int counter = 0;
	while (counter < 20)
	{
		walls.push_back(new Wall(&this->textures["WALL"],100.f,100.f));
		walls[counter]->rect.setPosition(counter * 100.f, -75.f);
		walls[counter]->sprite.setPosition(counter * 100.f, -75.f);
		counter++;
	}
	while (counter < 40)
	{
		walls.push_back(new Wall(&this->textures["WALL"],100.f, 100.f));
		walls[counter]->rect.setPosition((counter - 20) * 100.f, 1025.f);
		walls[counter]->sprite.setPosition((counter-20) * 100.f,1025.f);
		counter++;
	}
	while (counter < 55)
	{
		walls.push_back(new Wall(&this->textures["WALL"],100.f, 100.f));
		walls[counter]->rect.setPosition(-75.f, (counter - 40) * 100.f);
		walls[counter]->sprite.setPosition(-75.f, (counter - 40) * 100.f);
		counter++;
	}
	while (counter < 70)
	{
		walls.push_back(new Wall(&this->textures["WALL"],100.f, 100.f));
		walls[counter]->rect.setPosition(1895.f, (counter - 55) * 100.f);
		walls[counter]->sprite.setPosition( 1895.f, (counter - 55) *100.f);
		counter++;
	}
	while (counter < 75)
	{
		walls.push_back(new Wall(&this->textures["WALL"], 100.f, 100.f));
		walls[counter]->rect.setPosition(400.f, (counter - 70) * 100.f+300.f);
		walls[counter]->sprite.setPosition(400.f, (counter - 70) * 100.f + 300.f);
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
		waters[counterW]->rect.setPosition((counterW-3) * 100.f + 800.f, 450.f);
		waters[counterW]->sprite.setPosition((counterW-3) * 100.f + 800.f, 450.f);
		counterW++;
	}
	while (counterW < 9)
	{
		waters.push_back(new Water(&this->textures["WATER"], 100.f, 100.f));
		waters[counterW]->rect.setPosition((counterW-6) * 100.f + 800.f, 550.f);
		waters[counterW]->sprite.setPosition((counterW-6)* 100.f + 800.f, 550.f);
		counterW++;
	}
	int counterB = 0;
	while (counterB < 4)
	{
		breakables.push_back(new Breakable(&this->textures["CRATE"], 75.f, 75.f));
		breakables[counterB]->rect.setPosition(counterB * 75.f + 1595.f, 25.f);
		breakables[counterB]->sprite.setPosition(counterB * 75.f + 1595.f, 25.f);
		counterB++;
	}
	

}

//Constructors/Destructors
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window,supportedKeys,states)
{
	this->initKeybinds();
	this->initFonts();
	this->initTextures();
	this->initPauseMenu();
	this->initMap();
	this->initPlayers();
	this->initBackground();
}

GameState::~GameState()
{
	delete this->pmenu;
	delete this->player;
	for (auto* i : this->bullets)
	{
		delete i;
	}
}

void GameState::enemyAI()
{
	float timer = clock.getElapsedTime().asSeconds();
	for (int k = 0; k < enemies.size(); k++)
	{
		if (enemies[k]->aggroed == true)
		{
			if (timer >= 0.10)
			{
				clock.restart();
				int tempRand = generateRandom(2);
				if (tempRand == 1&& enemies[k]->canAttack())//Enemy fire bullet
				{
					//Player to right
					if ((player->rect.getPosition().x < enemies[k]->rect.getPosition().x) &&
						(abs(player->rect.getPosition().y - enemies[k]->rect.getPosition().y)) <= 500.f)
					{
						dir_xE = -1.f;
						dir_yE = 0.f;
						this->bulletsE.push_back(new Bullet(&this->textures["BULLET"], 
							this->enemies[k]->rect.getPosition().x, this->enemies[k]->rect.getPosition().y,
							dir_xE, dir_yE, 5.f));
						enemies[k]->direction = 1;
					}
					//Player to left
					else if((player->rect.getPosition().x > enemies[k]->rect.getPosition().x) &&
						(abs(player->rect.getPosition().y - enemies[k]->rect.getPosition().y) <= 500.f))
					{
						dir_xE = 1.f;
						dir_yE = 0.f;
						this->bulletsE.push_back(new Bullet(&this->textures["BULLET"],
							this->enemies[k]->rect.getPosition().x, this->enemies[k]->rect.getPosition().y,
							dir_xE, dir_yE, 5.f));
						enemies[k]->direction = 2;
					}

					//Player to top
					else if((player->rect.getPosition().y < enemies[k]->rect.getPosition().y) &&
						(abs(player->rect.getPosition().x - enemies[k]->rect.getPosition().x) <= 500.f))
					{
						dir_xE = 0.f;
						dir_yE = -1.f;
						this->bulletsE.push_back(new Bullet(&this->textures["BULLET"],
							this->enemies[k]->rect.getPosition().x, this->enemies[k]->rect.getPosition().y,
							dir_xE, dir_yE, 5.f));
						enemies[k]->direction = 3;
					}
					//Plyer to bottom
					else if((player->rect.getPosition().y > enemies[k]->rect.getPosition().y) &&
						(abs(player->rect.getPosition().x - enemies[k]->rect.getPosition().x) <= 500.f))
					{
						dir_xE = 0.f;
						dir_yE = 1.f;
						this->bulletsE.push_back(new Bullet(&this->textures["BULLET"],
							this->enemies[k]->rect.getPosition().x, this->enemies[k]->rect.getPosition().y,
							dir_xE, dir_yE, 5.f));
						enemies[k]->direction = 4;
					}

				}
				else if (tempRand == 2)//Enemy chasing
				{
					if (player->rect.getPosition().y < enemies[k]->rect.getPosition().y)
					{
						enemies[k]->direction = 3;
					}
					else if (player->rect.getPosition().y > enemies[k]->rect.getPosition().y)
					{
						enemies[k]->direction = 4;
					}
					else if (player->rect.getPosition().x < enemies[k]->rect.getPosition().x)
					{
						enemies[k]->direction = 1;
					}
					else if (player->rect.getPosition().x > enemies[k]->rect.getPosition().x)
					{
						enemies[k]->direction = 2;
					}
				}
				else if(tempRand==3)//Enemy chasing
				{

					if (player->rect.getPosition().x < enemies[k]->rect.getPosition().x)
					{
						enemies[k]->direction = 1;
					}
					else if (player->rect.getPosition().x > enemies[k]->rect.getPosition().x)
					{
						enemies[k]->direction = 2;
					}					
					else if (player->rect.getPosition().y < enemies[k]->rect.getPosition().y)
					{
						enemies[k]->direction = 3;
					}
					else if (player->rect.getPosition().y > enemies[k]->rect.getPosition().y)
					{
						enemies[k]->direction = 4;
					}
				}
			}
		}
	}
}

void GameState::initText(std::string str,float x,float y)
{
	this->GameText.setFont(font);
	this->GameText.setFillColor(sf::Color(255, 255, 255, 200));
	this->GameText.setCharacterSize(30);
	this->GameText.setString(str+std::to_string(this->points));
	this->GameText.setPosition(x,y);
}

void GameState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE")))&&this->getKeyTime())
	{
		if (!this->paused)
			this->pauseState();
		else
			this->unpauseState();
	}
}

void GameState::updatePlayerInput(const float& dt)
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
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) )
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("FIRE")))&&this->player->canAttack())
	{
		this->bullets.push_back(new Bullet(&this->textures["BULLET"],this->player->rect.getPosition().x, this->player->rect.getPosition().y, dir_x, dir_y,5.f));
	}	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("SPAWN"))) && this->canSpawn())
	{
		this->enemies.push_back(new Enemy(&this->textures["ENEMY"],1700.f-generateRandom0(2)*200.f, generateRandom(4)*200.f, 1.5));
	}
}

void GameState::updatePauseButtons()
{
	if (this->pmenu->isButtonPressed("QUIT"))
		this->endState();
}

void GameState::updateBullets()
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

void GameState::updateEnemySpawn()
{
	if (this->spawnCooldown < this->spawnCooldownMax)
		this->spawnCooldown += 1.f;
}

void GameState::updateMap()
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

const bool GameState::canSpawn()
{
	if (this->spawnCooldown >= this->spawnCooldownMax)
	{
		this->spawnCooldown = 0.f;
		return true;
	}
	return false;
}

void GameState::collision()
{
	//Destroying enemies with the bullet
	for (int k= 0; k < this->enemies.size(); ++k)
	{
		
		for (size_t i = 0;  i< this->bullets.size(); i++)
		{
		if (this->bullets[i]->rect.getGlobalBounds().intersects(this->enemies[k]->rect.getGlobalBounds()))
			{
			this->bullets[i]->isDestroyed = true;
			enemies[k]->hp-=bullets[i]->attackDamage;
			enemies[k]->aggroed = true;
			if (enemies[k]->hp <= 0)
			{
				enemies[k]->alive = false;
			}
			if (this->bullets[i]->isDestroyed == true)
			{
				this->bullets.erase(this->bullets.begin() + i);
			}
			
			//this->enemies.erase(this->enemies.begin() + k);
			}
		}
	}
	for (int k = 0; k < enemies.size(); k++)
	{
		if (enemies[k]->alive == false)
		{
			enemies.erase(this->enemies.begin() + k);
			points += 5;
			break;
		}
	}
	//Destroying bullets
	for (int i = 0; i < this->bullets.size(); i++)
	{
		if (this->bullets[i]->isDestroyed == true)
		{
			this->bullets.erase(this->bullets.begin() + i);
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
				player->rect.move(0.f,1.f);
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
	}
	//Enemy collides the wall
	for (int k = 0; k < enemies.size(); k++)
	{
		for (int w = 0; w < walls.size(); w++)
		{
			if (enemies[k]->rect.getGlobalBounds().intersects(walls[w]->rect.getGlobalBounds()))
			{
				if (enemies[k]->direction == 1)//left
				{
					enemies[k]->canMoveLeft = false;
					enemies[k]->rect.move(1.f, 0.f);
				}
				else if (enemies[k]->direction == 2)//right
				{
					enemies[k]->canMoveRight = false;
					enemies[k]->rect.move(-1.f, 0.f);
				}
				else if (enemies[k]->direction == 3)//up
				{
					enemies[k]->canMoveUp = false;
					enemies[k]->rect.move(0.f, 1.f);
				}
				else if (enemies[k]->direction == 4)//down
				{
					enemies[k]->canMoveDown = false;
					enemies[k]->rect.move(0.f, -1.f);
				}
				else
				{

				}
			}

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
	}
	//Enemy collides the water
	for (int k = 0; k < enemies.size(); k++)
	{
		for (int w = 0; w < waters.size(); w++)
		{
			if (enemies[k]->rect.getGlobalBounds().intersects(waters[w]->rect.getGlobalBounds()))
			{
				if (enemies[k]->direction == 1)//left
				{
					enemies[k]->canMoveLeft = false;
					enemies[k]->rect.move(1.f, 0.f);
				}
				else if (enemies[k]->direction == 2)//right
				{
					enemies[k]->canMoveRight = false;
					enemies[k]->rect.move(-1.f, 0.f);
				}
				else if (enemies[k]->direction == 3)//up
				{
					enemies[k]->canMoveUp = false;
					enemies[k]->rect.move(0.f, 1.f);
				}
				else if (enemies[k]->direction == 4)//down
				{
					enemies[k]->canMoveDown = false;
					enemies[k]->rect.move(0.f, -1.f);
				}
				else
				{

				}
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
	}
	//Enemy collides with crate
	for (int k = 0; k < enemies.size(); k++)
	{
		for (int b = 0; b < breakables.size(); b++)
		{
			if (enemies[k]->rect.getGlobalBounds().intersects(breakables[b]->rect.getGlobalBounds()))
			{
				if (enemies[k]->direction == 1)//left
				{
					enemies[k]->canMoveLeft = false;
					enemies[k]->rect.move(1.f, 0.f);
				}
				else if (enemies[k]->direction == 2)//right
				{
					enemies[k]->canMoveRight = false;
					enemies[k]->rect.move(-1.f, 0.f);
				}
				else if (enemies[k]->direction == 3)//up
				{
					enemies[k]->canMoveUp = false;
					enemies[k]->rect.move(0.f, 1.f);
				}
				else if (enemies[k]->direction == 4)//down
				{
					enemies[k]->canMoveDown = false;
					enemies[k]->rect.move(0.f, -1.f);
				}
				else
				{

				}
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
				this->breakables[b]->isDestroyed=true;
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
	}
	//Enemy bullets collides the player
	for (size_t i = 0; i < this->bulletsE.size(); i++)
	{
		if (this->bulletsE[i]->rect.getGlobalBounds().intersects(this->player->rect.getGlobalBounds()))
		{
			this->bulletsE[i]->isDestroyed = true;
			player->hp -= bulletsE[i]->attackDamage;
			if (player->hp <= 0)
			{
				player->isAlive = false;
			}
			if (this->bulletsE[i]->isDestroyed == true)
			{
				this->bulletsE.erase(this->bulletsE.begin() + i);
			}

			//this->enemies.erase(this->enemies.begin() + k);
		}
	}
	//Enemy bullets collides the crate
	for (int b = 0; b < this->breakables.size(); ++b)
	{
		for (size_t i = 0; i < this->bulletsE.size(); i++)
		{
			if (this->bulletsE[i]->rect.getGlobalBounds().intersects(this->breakables[b]->rect.getGlobalBounds()))
			{
				this->bulletsE[i]->isDestroyed = true;
				this->breakables[b]->isDestroyed = true;
				if (this->bulletsE[i]->isDestroyed == true)
				{
					this->bulletsE.erase(this->bulletsE.begin() + i);
				}
				if (this->breakables[b]->isDestroyed == true)
				{
					this->breakables.erase(this->breakables.begin() + b);
				}

				//this->enemies.erase(this->enemies.begin() + k);
			}
		}
	}
	//Enemy bullets collides the wall
	for (int w = 0; w < this->walls.size(); ++w)
	{
		for (size_t i = 0; i < this->bulletsE.size(); i++)
		{
			if (this->bulletsE[i]->rect.getGlobalBounds().intersects(this->walls[w]->rect.getGlobalBounds()))
			{
				this->bulletsE[i]->isDestroyed = true;
				if (this->bulletsE[i]->isDestroyed == true)
				{
					this->bulletsE.erase(this->bulletsE.begin() + i);
				}

				//this->enemies.erase(this->enemies.begin() + k);
			}
		}
	}
}

void GameState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateKeyTime(dt);
	this->updateInput(dt);
	this->enemyAI();
	this->initText("Points:", 10.f, 1015.f);
	if (!this->paused) //Unpaused update
	{
		if (this->player->isAlive == true)
		{
			this->updatePlayerInput(dt);
			//this->updateBullets();
			this->player->update(dt);
		}
		if (this->player->isAlive == false)
		{
			this->player->sprite.setTexture(this->textures["DEAD"]);
			this->GameOverText.setFont(font);
			this->GameOverText.setFillColor(sf::Color::Red);
			this->GameOverText.setCharacterSize(100);
			this->GameOverText.setString("GAME OVER");
			this->GameOverText.setPosition(750, 450);
		}
		this->updateEnemySpawn();
		this->collision();
		for (int i = 0; i < this->bullets.size(); i++)
		{
			bullets[i]->update();
		}
		for (int e = 0; e < this->bulletsE.size(); e++)
		{
			bulletsE[e]->update();
		}
		for (int k = 0; k < enemies.size(); k++)
		{
			enemies[k]->update();
			enemies[k]->updateMovement();
		}
	}
	else //Paused update
	{
		this->pmenu->update(this->mousePosView);
		this->updatePauseButtons();
	}
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(this->background);
	this->updateMap();
	this->player->render(target);
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
	for (int e = 0; e < bulletsE.size(); e++)
	{
		target->draw(bulletsE[e]->sprite);
		//target->draw(bullets[i]->rect);
	}
	if (!this->paused) //pause menu render
	{
		target->draw(this->GameOverText);
	}
	if (this->paused) //pause menu render
	{
		this->pmenu->render(*target);
	}
	target->draw(this->GameText);
	
}
