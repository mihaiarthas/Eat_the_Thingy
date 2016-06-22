#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>

using namespace std;

class Food
{
public:
	Food(int, int);
	~Food();
	sf::Sprite getFoodSprite();
	void ifCollision(int, int);

protected:
	sf::Sprite foodSprite;
	sf::Texture foodTexture;
};

