#include "Game.h"

//Static functions

void Game::initVariables()
{
	this->window = NULL;
	this->fullscreen = false;
	this->dt = 0.f;
}

//Initializer functions
void Game::initWindow()
{
	std::ifstream ifs("config/window.ini");
	this->videoModes = sf::VideoMode::getFullscreenModes();

	std::string title = "None";
	sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
	bool fullscreen = false;
	unsigned framerate_limit = 144;
	bool vertical_sync_enabled = false;
	unsigned antialising_level = 0;

	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> fullscreen;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
		ifs >> antialising_level;
	}

	ifs.close();

	this->fullscreen = false; //fullscreen;
	this->windowSettings.antialiasingLevel = antialising_level;

	if (this->fullscreen)
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen, windowSettings);
	else
		this->window = new sf::RenderWindow(window_bounds, title,sf::Style::Titlebar | sf::Style::Close , windowSettings);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initKeys()
{
	std::ifstream ifs("config/supported_keys.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		int key_value = 0;
		while (ifs >> key >> key_value)
		{
			this->supportedKeys[key] = key_value;
		}
	}

	ifs.close();

	//DEBUG REMOVE LATER!
	//for (auto i : this->supportedKeys)
	//{
	//	std::cout << i.first << " " << i.second << "\n";
	//}
}

void Game::initStates()
{
	this->states.push(new MainMenuState(this->window, &this->supportedKeys,&this->states));
	//this->states.push(new GameState(this->window,&this->supportedKeys));
}

//Constructors/Destructors
Game::Game()
{
	this->initWindow();
	this->initKeys();
	this->initStates();
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

//Functions

void Game::endApplication()
{
	std::cout << "Ending application";
}

void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateEvents()
{
	while (this->window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					this->window->close();
			}
}

void Game::update()
{
	
	this->updateEvents();

	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);
		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}

	//Application end
	else
	{
		this->endApplication();
		this->window->close();
	}
	//if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) { herosprite.move(-0.1 * time, 0); herosprite.setTextureRect(sf::IntRect(67, 1, 28, 28)); } //добавили управление на клавиши W,S,A,D
	//	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) { herosprite.move(0.1 * time, 0); herosprite.setTextureRect(sf::IntRect(193, 1, 28, 28)); }
	//	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) { herosprite.move(0, -0.1 * time); herosprite.setTextureRect(sf::IntRect(1, 3, 28, 28)); }
	//	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) { herosprite.move(0, 0.1 * time); herosprite.setTextureRect(sf::IntRect(129, 1, 28, 28)); }

	//	
	//	this->window->draw(herosprite);
}

void Game::render()
{
	this->window->clear(sf::Color::Black);

	//Render Items
	if (!this->states.empty())
		this->states.top()->render();

	this->window->display();
}

void Game::run()
{

	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
		
	}
}
