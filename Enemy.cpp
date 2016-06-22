#include "Enemy.h"
#include <iostream>

using namespace std;


Enemy::Enemy(int width, int height)
{
	if (!enemyTexture.loadFromFile("policecar.png"))
	{
		cout << "Player texture not loaded" << endl;
	}
	enemySprite.setTexture(enemyTexture);
	enemySprite.setOrigin(sf::Vector2f(enemySprite.getTexture()->getSize().x * 0.5, enemySprite.getTexture()->getSize().y * 0.5));
	enemySprite.setPosition(100, height);
	this->velocity = 5;
	int xRect = enemySprite.getTexture()->getSize().x;
	int yRect = enemySprite.getTexture()->getSize().y;
	enemySprite.setTextureRect({ 0,0,xRect,yRect });
}

sf::Sprite Enemy::getEnemySprite()
{
	return this->enemySprite;
}

void Enemy::updateEnemy(int width, int height)
{
	int random = rand() % 10 + 1;
	enemySprite.move(std::sin(3.14159265 * enemySprite.getRotation() / 180.f) * velocity, -1 * std::cos(3.14159265 * enemySprite.getRotation() / 180.f) * velocity);
	if(random < 2)
		enemySprite.rotate(-10);
	if (random > 8)
		enemySprite.rotate(10);
	if (enemySprite.getPosition().y < 0)
		enemySprite.setPosition(sf::Vector2f(enemySprite.getPosition().x, height));
	if (enemySprite.getPosition().x > width)
		enemySprite.setPosition(sf::Vector2f(0, enemySprite.getPosition().y));
	if (enemySprite.getPosition().y > height)
		enemySprite.setPosition(sf::Vector2f(enemySprite.getPosition().x, 0));
	if (enemySprite.getPosition().x < 0)
		enemySprite.setPosition(sf::Vector2f(width, enemySprite.getPosition().y));

}

void Enemy::resetEnemy(int width, int height)
{
	enemySprite.setPosition(100, height);
}

Enemy::~Enemy()
{
}
