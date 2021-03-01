#pragma once
#include <Level.h>
#include <iostream>
class GameoverLevel : public ty::Level
{
public:
	GameoverLevel(class ty::Application* app);
	virtual void Tick(float DeltaTime) override;
	virtual void DrawBackground() override;
private:
	sf::Sprite m_GameoverTitle;
	sf::Sprite m_GameoverBody;

	sf::Text m_scoreText;
	sf::Font m_scoreFont;

	sf::Text m_highscoreText;
};