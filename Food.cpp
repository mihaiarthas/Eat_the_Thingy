#include "Food.h"



Food::Food(int width,int height)
{
	if (!foodTexture.loadFromFile("heineken.png"))
	{
		cout << "Food texture not loaded" << endl;
	}
	foodSprite.setTexture(foodTexture);
	foodSprite.setOrigin(sf::Vector2f(foodSprite.getTexture()->getSize().x * 0.5, foodSprite.getTexture()->getSize().y * 0.5));
//	int mWidth = width - 50;
//	int mHeight = height - 50;
//	int randWidth = rand() % (mWidth - 50 + 1) + 50;
//	int randHeight = rand() % (mHeight - 50 + 1) + 50;
	foodSprite.setPosition(sf::Vector2f(width / 2, height / 2));
}

void Food::ifCollision(int width, int height)
{
	int mWidth = width - 50;
	int mHeight = height - 50;
	int randWidth = rand() % (mWidth - 50 + 1) + 50;
	int randHeight = rand() % (mHeight - 50 + 1) + 50;
	foodSprite.setPosition(sf::Vector2f(randWidth, randHeight));
}

sf::Sprite Food::getFoodSprite()
{
	return this->foodSprite;
}

Food::~Food()
{
}
