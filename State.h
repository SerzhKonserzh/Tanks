#pragma once
#include "Player.h"
class State
{ 
private:

protected:
	std::stack<State*>* states;
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;
	bool paused;
	float keyTime;
	float keyTimeMax;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Resources
	std::map<std::string,sf::Texture> textures;

	//Functions
	virtual void initKeybinds() = 0;
public:
	State(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys, std::stack<State*>* states);
	virtual ~State();
	//Accessors
	const bool& getQuit();
	const bool getKeyTime();

	void endState();
	void pauseState();
	void unpauseState();
	//Pure virtual functions(we need them for correct inheritage)
	virtual void updateMousePositions();
	virtual void updateKeyTime(const float dt);
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt)=0;
	virtual void render(sf::RenderTarget* target=nullptr)=0;
};

