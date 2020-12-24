#pragma once
#include "MainMenuState.h"
class Game
{
private:
	//Variables
	sf::RenderWindow *window;
	sf::Event event;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;
	bool fullscreen;

	sf::Clock dtClock;
	float dt; //delta time
	
	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;
	//Initialization
	void initVariables();
	void initWindow();
	void initKeys();
	void initStates();

public:
	//Constructors/Destructors
	Game();
	virtual ~Game();

	//Functions
	//Regular
	void endApplication();
	//Update
	void updateDt();
	void updateEvents();
	void update();
	//Render
	void render();
	//Core
	void run();
};

