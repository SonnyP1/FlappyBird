#include "MainGameLevel.h"
#include <Application.h>
#include "Bird.h"
#include "Pipe.h"
#include "PipeGenerator.h"
MainGameLevel::MainGameLevel(class ty::Application* app)
	:Level(app),
	m_BackGroundSpeed(20.f),isGameOver(false)
{
	SetBackGround("background.png");
	m_BackGround_Cpy.setTexture(LoadTexture("background.png"));
	unsigned int xOffset = app->GetWindow()->getSize().x;
	m_BackGround_Cpy.setPosition((float)xOffset,0.f);

	AddEntity(std::shared_ptr<Bird>(new Bird(this)));
	AddEntity(std::shared_ptr<PipeGenerator>(new PipeGenerator(this)));

	m_scoreFont.loadFromFile("Resources/Fonts/PixelDart.ttf");
	m_scoreText.setFont(m_scoreFont);
	m_scoreText.setString(std::to_string(GetApp()->GetScore()));
	m_scoreText.setCharacterSize(100);
	m_scoreText.setFillColor(sf::Color::Yellow);
	m_scoreText.setPosition(350, 100);
}

void MainGameLevel::Tick(float DeltaTime)
{
	Level::Tick(DeltaTime);
	sf::Vector2f offset(-DeltaTime * m_BackGroundSpeed, 0);
	GetBackGround().move(offset);
	m_BackGround_Cpy.setPosition(GetBackGround().getPosition().x + GetApp()->GetWindow()->getSize().x,0);
	m_scoreText.setString(std::to_string(GetApp()->GetScore()));
	if (m_BackGround_Cpy.getPosition().x <= 0)
	{
		GetBackGround().setPosition(0.f, 0.f);
		m_BackGround_Cpy.setPosition(GetApp()->GetWindow()->getSize().x, 0.f);
	}
}

void MainGameLevel::DrawBackground()
{
	GetApp()->GetWindow()->draw(GetBackGround());
	GetApp()->GetWindow()->draw(m_BackGround_Cpy);
	GetApp()->GetWindow()->draw(m_scoreText);
}
