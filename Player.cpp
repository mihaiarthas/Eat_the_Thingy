#include "Player.h"
#include <sstream>
using namespace std;


Player::Player(int width, int height)
{
	if (!playerTexture.loadFromFile("car.png"))
	{
		cout << "Player texture not loaded" << endl;
	}
	playerSprite.setTexture(playerTexture);
	playerSprite.setOrigin(sf::Vector2f(playerSprite.getTexture()->getSize().x * 0.5, playerSprite.getTexture()->getSize().y * 0.5));
	playerSprite.setPosition(width / 2, height - playerSprite.getTexture()->getSize().x * 0.5);
	this->score = 0;
	this->velocity = 10;
	int xRect = playerSprite.getTexture()->getSize().x;
	int yRect = playerSprite.getTexture()->getSize().y;
	playerSprite.setTextureRect({ 0,0, xRect,yRect });

	scoreBuffer.loadFromFile("drink.wav");
	scoreSound.setBuffer(scoreBuffer);
}

sf::Sprite Player::getPlayerSprite()
{
	return this->playerSprite;
}

void Player::updateMovement(int width, int height)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		playerSprite.move(std::sin(3.14159265 * playerSprite.getRotation() / 180.f) * velocity, -1 * std::cos(3.14159265 * playerSprite.getRotation() / 180.f) * velocity);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		playerSprite.move((std::sin(3.14159265 * playerSprite.getRotation() / 180.f) * velocity/2) * (-1), -1 * (-1 * std::cos(3.14159265 * playerSprite.getRotation() / 180.f) * velocity/2));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			playerSprite.rotate(-10);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			playerSprite.rotate(-10);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			playerSprite.rotate(10);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			playerSprite.rotate(10);
	}

	if (playerSprite.getPosition().y < 0)
		playerSprite.setPosition(sf::Vector2f(playerSprite.getPosition().x, height));
	if (playerSprite.getPosition().x > width)
		playerSprite.setPosition(sf::Vector2f(0, playerSprite.getPosition().y));
	if (playerSprite.getPosition().y > height)
		playerSprite.setPosition(sf::Vector2f(playerSprite.getPosition().x, 0));
	if (playerSprite.getPosition().x < 0)
		playerSprite.setPosition(sf::Vector2f(width, playerSprite.getPosition().y));
}

void Player::addScore(int score)
{
	this->score += score;
	scoreSound.play();
}

int Player::getScore()
{
	return this->score;
}

int Player::displayScore()
{
	return this->score;
}

void Player::resetPlayer(int width, int height)
{
	playerSprite.setPosition(width / 2, height - playerSprite.getTexture()->getSize().x * 0.5);
	this->score = 0;
	playerSprite.setRotation(0);
}

Player::~Player()
{
}
