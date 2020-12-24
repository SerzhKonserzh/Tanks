#pragma once
#include "GameState.h"
class DuoState :
	public State
{
private:
	sf::Font font;
	PauseMenu* pmenu;
	float dir_x = 0.f;
	float dir_y = -1.f;
	float dir_x2 = 0.f;
	float dir_y2 = -1.f;
	float timer = 100.f;
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Clock clock;
	sf::Time elapsed;
	sf::Text DuoText;

	float spawnCooldown = 150.f;
	float spawnCooldownMax = 150.f;

	Player* player,*player2;
	Enemy* enemy;
	Wall* wall;
	Water* water;
	Breakable* breakable;

	std::vector<Bullet*> bullets;
	std::vector<Bullet*> bullets2;
	std::vector<Enemy*> enemies;
	std::vector<Wall*> walls;
	std::vector<Water*> waters;
	std::vector<Breakable*> breakables;

	//Functions

	void initKeybinds();
	void initFonts();
	void initTextures();
	void initPauseMenu();
	void initPlayers();
	void initMap();
	void initBackground();

public:
	DuoState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~DuoState();

	//Functions
	void initText(std::string str, float x, float y);
	void updateInput(const float& dt);
	void updatePlayerInput(const float& dt);
	void updatePauseButtons();
	void updateBullets();
	void updateEnemySpawn();
	void updateMap();
	const bool canSpawn();
	void collision();
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);

};

