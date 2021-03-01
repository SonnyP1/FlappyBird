#include "PlayButton.h"
#include "FlappyBirdApp.h"
#include "MainGameLevel.h"
#include <iostream>
PlayButton::PlayButton(ty::Level* level)
	:Entity(level)
{
}

void PlayButton::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		std::cout << "I PRESSED SPACE" << std::endl;
		GetApp()->ResetScore();
		GetApp()->LoadLevel(new MainGameLevel(GetApp()));
		//FlappyBirdApp* app = new FlappyBirdApp(768, 1024, "FlappyBird");
		//app->LoadLevel(new MainGameLevel(app));
	}
}
