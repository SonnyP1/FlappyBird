#include "MainGameLevel.h"
#include <Application.h>
MainGameLevel::MainGameLevel(class ty::Application* app)
	:Level(app),
	m_BackGroundSpeed(20.f)
{
	SetBackGround("background.png");
	m_BackGround_Cpy.setTexture(LoadTexture("background.png"));
	unsigned int xOffset = app->GetWindow()->getSize().x;
	m_BackGround_Cpy.setPosition((float)xOffset,0.f);
}

void MainGameLevel::Tick(float DeltaTime)
{
	sf::Vector2f offset(-DeltaTime * m_BackGroundSpeed, 0);
	GetBackGround().move(offset);
	m_BackGround_Cpy.setPosition(GetBackGround().getPosition().x + GetApp()->GetWindow()->getSize().x,0);
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
}
