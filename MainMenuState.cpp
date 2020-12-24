#include "MainMenuState.h"

//Initializer functions
void MainMenuState::initVariables()
{

}

void MainMenuState::initBackground()
{
	this->background.setSize(
		sf::Vector2f
	(
		static_cast<float>(this->window->getSize().x),
		static_cast<float>( this->window->getSize().y))
	);
	
	if (!this->backgroundTexture.loadFromFile("images/background.jpg"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}

	this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("fonts/MachineBT.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::initKeybinds()
{
	std::ifstream ifs("config/mainmenustate_keybinds.ini");

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

void MainMenuState::initButtons()
{
	this->str = L"Single game";
	this->buttons["GAME_STATE"] = new Button(300.f, 300.f, 200.f, 75.f,
		&this->font,str,48,
		sf::Color(255, 0, 0, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 200),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
	this->str = L"PvP";
	this->buttons["DUO_STATE"] = new Button(300.f, 400.f, 200.f, 75.f,
		&this->font, str, 48,
		sf::Color(255, 0, 0, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 200),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
	this->str = L"Settings";
	this->buttons["SETTINGS_STATE"] = new Button(300.f, 500.f, 200.f, 75.f,
		&this->font, str,50,
		sf::Color(255, 0, 0, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 200),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
	this->str = L"Quit";
	this->buttons["EXIT"] = new Button(300.f, 750.f, 200.f, 75.f,
		&this->font, str,50,
		sf::Color(255, 0, 0, 200), sf::Color(250, 250, 250, 255), sf::Color(20, 20, 20, 200),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys,states)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}




void MainMenuState::updateInput(const float& dt)
{
	

}

void MainMenuState::updateButtons()
{
	//Updates all the buttons in state and there functionality
	for (auto& it : this->buttons)//fastest loop
	{
		it.second->update(this->mousePosView);
	}

	//New game
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->states->push(new GameState(this->window, this->supportedKeys,this->states));
	}
	//Duo
	if (this->buttons["DUO_STATE"]->isPressed())
	{
		this->states->push(new DuoState(this->window, this->supportedKeys, this->states));
	}

	//Settings
	if (this->buttons["SETTINGS_STATE"]->isPressed())
	{
		this->states->push(new SettingsState(this->window, this->supportedKeys, this->states));
	}

	//Quit the game
	if (this->buttons["EXIT"]->isPressed())
	{
		this->endState();
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons(); 
}

void MainMenuState::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)//fastest loop
	{
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(this->background);

	this->renderButtons(*target);

	//Renove later
	//sf::Text mouseText;
	//mouseText.setPosition(this->mousePosView.x, mousePosView.y -10);
	//mouseText.setFont(this->font);
	//mouseText.setCharacterSize(12);
	//std::stringstream ss;
	//ss << this->mousePosView.x << " " << mousePosView.y;
	//mouseText.setString(ss.str());
	//target->draw(mouseText);
}
