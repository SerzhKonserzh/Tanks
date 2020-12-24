#pragma once
#include "State.h"
#include "PauseMenu.h"
#include "Bullet.h"
#include "Breakable.h"
class GameState :
	public State
{
private:
	sf::Font font;
	PauseMenu* pmenu;
	float dir_x = 0.f;
	float dir_y = -1.f;
	float dir_xE = 0.f;
	float dir_yE = -1.f;
	float timer = 100.f;
	int points=0;
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Clock clock;
	sf::Time elapsed;
	sf::Text GameText;
	sf::Text GameOverText;

	float spawnCooldown=150.f;
	float spawnCooldownMax=150.f;

	Player* player;
	Enemy* enemy;
	Wall* wall;
	Water* water;
	Breakable* breakable;

	std::vector<Bullet*> bullets;
	std::vector<Bullet*> bulletsE;
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
	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~GameState();

	//Functions
	void enemyAI();
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

