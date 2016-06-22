#include <SFML\Graphics.hpp>
#include "SFML\Audio.hpp"
#include <iostream>
#include <sstream>
#include "Player.h"
#include "Food.h"
#include "Enemy.h"
#include "Menu.h"
#include<fstream>

using namespace std;

ifstream fin("HIGH_SCORE.txt");
ofstream fout("HIGH_SCORE.txt");

int main()
{
	int width = 800;
	int height = 600;
	bool start = false;
	
	int i;
	fin >> i;
	cout << i;
	fin.close();
	fout << 2113;

	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(width, height), "Eat the Thingy");
	window.setFramerateLimit(30);

	sf::Texture background;
	background.loadFromFile("concrete.jpg");
	background.setRepeated(true);
	sf::Sprite BG;
	BG.setTexture(background);
	BG.setTextureRect({ 0,0,width,height });

	Player player(width, height);
	Food food(width, height);
	Enemy enemy(width, height);

	sf::Font font;
	font.loadFromFile("Squares Bold Free.otf");
	sf::Text text;
	sf::Text scoreString;
	stringstream ss;
	ss << player.getScore();
	text.setString(ss.str().c_str());
	text.setFont(font);
	text.setColor(sf::Color::Yellow);
	text.setCharacterSize(20);
	text.setPosition(100, 0);
	scoreString.setFont(font);
	scoreString.setColor(sf::Color::Yellow);
	scoreString.setCharacterSize(20);
	scoreString.setString(" Score : ");

	Menu menu(width, height);

	sf::SoundBuffer crashBuffer;
	crashBuffer.loadFromFile("crash.wav");
	sf::Sound crashSound;
	crashSound.setBuffer(crashBuffer);
	sf::Music music;
	music.openFromFile("beat.wav");
	music.play();
	music.setVolume(25);
	music.setLoop(true);
	sf::Music siren;
	siren.openFromFile("siren.wav");
	siren.setLoop(true);
	siren.setVolume(50);
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}
		window.clear();
		if (player.getPlayerSprite().getGlobalBounds().intersects(food.getFoodSprite().getGlobalBounds()))
		{
			food.ifCollision(width, height);
			player.addScore(10);

		}
		if (player.getPlayerSprite().getGlobalBounds().intersects(enemy.getEnemySprite().getGlobalBounds()))
		{
			siren.play();
			crashSound.play();
			while (true)
			{	
				text.setPosition(width / 2 + 100 , height / 2);
				text.setCharacterSize(50);
				scoreString.setPosition(width / 2 - 150, height / 2);
				scoreString.setCharacterSize(50);

				sf::Text over;
				over.setFont(font);
				over.setColor(sf::Color::Red);
				over.setCharacterSize(50);
				over.setString("BUSTED !");
				over.setPosition(sf::Vector2f(width / 2 - 120, height / 2 - 80));
				over.setOrigin(sf::Vector2f(over.getScale().x * 0.5, over.getScale().y * 0.5));
				window.clear();
				if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					window.close();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
				{
					start = false;
					player.resetPlayer(width, height);
					enemy.resetEnemy(width, height);
					break;

				}
				window.draw(BG);
				window.draw(food.getFoodSprite());
				window.draw(enemy.getEnemySprite());
				window.draw(player.getPlayerSprite());
				window.draw(text);
				window.draw(scoreString);
				window.draw(over);
				window.display();
			}
		}

		stringstream ss;
		ss << player.getScore();
		text.setString(ss.str().c_str());
		if (start == false)
		{
			menu.draw(window);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				menu.MoveUp();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				menu.MoveDown();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				if (menu.GetPressedItem() == 0)
					start = true;
				if (menu.GetPressedItem() == 2)
					window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			} 
				
		} 
		
		if (start == true)
		{
			text.setPosition( 100, 0);
			text.setCharacterSize(20);
			scoreString.setPosition(0, 0);
			scoreString.setCharacterSize(20);

			siren.stop();
			player.updateMovement(width, height);
			enemy.updateEnemy(width, height);

			window.draw(BG);
			window.draw(food.getFoodSprite());
			window.draw(enemy.getEnemySprite());
			window.draw(player.getPlayerSprite());
			window.draw(text);
			window.draw(scoreString);
		}
		window.display();
	}
}