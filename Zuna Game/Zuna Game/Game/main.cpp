// Zuna.cpp : Defines the entry point for the console application.
//
//#define NOMINMAX
//#include <Windows.h>
#include "../../Scene/GameScene.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Zuna");
	std::unique_ptr<GameScene> mGameScene = std::make_unique<GameScene>();
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}

		window.clear();

		if (clock.getElapsedTime().asSeconds() >= 0.01f)
		{
			mGameScene->ProcessInput(window);
			mGameScene->Update(clock.getElapsedTime().asSeconds());
			clock.restart();
		}

		mGameScene->Draw(window);
		window.display();
	}

	return 0;
}