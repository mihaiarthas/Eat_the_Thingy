#pragma once
#include "SFML\Graphics.hpp"

class Enemy
{
public:
	Enemy(int, int);
	~Enemy();
	sf::Sprite getEnemySprite();
	void updateEnemy(int, int);
	void resetEnemy(int, int);
protected:
	sf::Texture enemyTexture;
	sf::Sprite enemySprite;
	int velocity;
};

