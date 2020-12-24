#include "SettingsState.h"

void SettingsState::initVariables()
{

}

void SettingsState::initBackground()
{
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y))
	);

	if (!this->backgroundTexture.loadFromFile("images/settings.jpg"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}

	this->background.setTexture(&this->backgroundTexture);
}

void SettingsState::initFonts()
{
	if (!this->font.loadFromFile("fonts/MachineBT.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void SettingsState::initKeybinds()
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

void SettingsState::initButtons()
{
	this->str = L"Выход";
	this->buttons["EXIT"] = new Button(300.f, 750.f, 200.f, 75.f,
		&this->font, str, 50,
		sf::Color(255, 0, 0, 200), sf::Color(250, 250, 250, 255), sf::Color(20, 20, 20, 200),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

SettingsState::SettingsState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window,supportedKeys,states)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	this->settingsText.setFont(font);
	this->settingsText.setFillColor(sf::Color::Red);
	this->settingsText.setCharacterSize(40);
	this->settingsText.setString("Resolution");
	this->settingsText.setPosition(300, 200);
}

SettingsState::~SettingsState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

//Functions
void SettingsState::updateInput(const float& dt)
{


}

void SettingsState::updateButtons()
{
	//Updates all the buttons in state and there functionality
	for (auto& it : this->buttons)//fastest loop
	{
		it.second->update(this->mousePosView);
	}



	//Quit
	if (this->buttons["EXIT"]->isPressed())
	{
		this->endState();
	}
}

void SettingsState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons();
}

void SettingsState::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)//fastest loop
	{
		it.second->render(target);
	}
}

void SettingsState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(this->background);

	this->renderButtons(*target);
	target->draw(this->settingsText);

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