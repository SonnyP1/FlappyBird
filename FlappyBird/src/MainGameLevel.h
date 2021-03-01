#pragma once
#include <Level.h>
class MainGameLevel : public ty::Level
{
public:
	MainGameLevel(class ty::Application* app);
	virtual void Tick(float DeltaTime) override;
	virtual void DrawBackground() override;
	bool isGameOver;
private:
	sf::Sprite m_BackGround_Cpy;
	float m_BackGroundSpeed;

	sf::Text m_scoreText;
	sf::Font m_scoreFont;
};