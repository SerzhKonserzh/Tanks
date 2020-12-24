#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include<vector>

#include "Button.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
class PauseMenu
{
private:
	sf::Font& font;
	sf::Text menuText;

	sf::RectangleShape background;
	sf::Texture containerTexture;
	sf::RectangleShape container;
	

	std::map<std::string, Button*> buttons;

public:
	std::wstring str;
	PauseMenu(sf::RenderWindow& window,sf::Font& font);
	virtual ~PauseMenu();
	//Accessors
	std::map<std::string, Button*>& getButtons();
	
	//Functions
	const bool isButtonPressed(const std::string key);
	void addButton(const std::string key, float y, const std::wstring text);
	void update(const sf::Vector2f& mousePos);
	void render(sf::RenderTarget& target);
};

