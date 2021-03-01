#include "GameoverLevel.h"
#include "PlayButton.h"
#include <string>
GameoverLevel::GameoverLevel(ty::Application* app)
	:Level(app)
{
	SetBackGround("background.png");
	m_GameoverBody.setTexture(LoadTexture("GameOverBody.png"));
	m_GameoverTitle.setTexture(LoadTexture("GameOverTitle.png"));

	m_GameoverBody.setPosition(100.f,100.f);
	m_GameoverTitle.setPosition(50.f,50.f);

	AddEntity(std::shared_ptr<PlayButton>(new PlayButton(this)));

	std::cout << "Score: " << GetApp()->GetScore() << std::endl;
	m_scoreFont.loadFromFile("Resources/Fonts/PixelDart.ttf");
	m_scoreText.setFont(m_scoreFont);
	m_scoreText.setString(std::to_string(GetApp()->GetScore()));
	m_scoreText.setCharacterSize(100);
	m_scoreText.setFillColor(sf::Color::Yellow);
	m_scoreText.setPosition(510, 145);

	std::cout << "HighScore: " << GetApp()->GetHighScore() << std::endl;
	m_highscoreText.setFont(m_scoreFont);
	m_highscoreText.setString(std::to_string(GetApp()->GetHighScore()));
	m_highscoreText.setCharacterSize(100);
	m_highscoreText.setFillColor(sf::Color::Yellow);
	m_highscoreText.setPosition(510, 250);
}

void GameoverLevel::Tick(float DeltaTime)
{
	Level::Tick(DeltaTime);
}

void GameoverLevel::DrawBackground()
{
	GetApp()->GetWindow()->draw(GetBackGround());

	GetApp()->GetWindow()->draw(m_GameoverBody);
	GetApp()->GetWindow()->draw(m_GameoverTitle);

	GetApp()->GetWindow()->draw(m_scoreText);
	GetApp()->GetWindow()->draw(m_highscoreText);
}
