#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include <iostream>

class Player
{
public:
	Player(int, int);
	~Player();
	sf::Sprite getPlayerSprite();
	void updateMovement(int , int);
	void addScore(int);
	int getScore();
	int displayScore();
	void resetPlayer(int, int);
protected:
	sf::Sprite playerSprite;
	sf::Texture playerTexture;
	int score;
	int velocity;
	sf::SoundBuffer scoreBuffer;
	sf::Sound scoreSound;

};

