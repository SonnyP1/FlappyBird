#include "..\include\Application.h"
#include <Application.h>
#include <tyrant.h>
#include <Level.h>

namespace ty
{
	Application::Application(int width, int height, const std::string& title)
		:m_window(new sf::RenderWindow(sf::VideoMode(width,height),title)),
		m_currentLevel(nullptr),
		m_Clock()
	{
		m_score = 0;
		m_highScore = 0;
	}

	Application::~Application()
	{
		if (m_window)
		{
			delete m_window;
		}
		if (m_currentLevel)
		{
			delete m_currentLevel;
		}
	}
	void Application::Run()
	{
		BeginPlay();
		if (m_window)
		{
			float previousFrameStartTime = m_Clock.getElapsedTime().asSeconds();
			while (m_window->isOpen())
			{
				float currentFrameStartTime = m_Clock.getElapsedTime().asSeconds();
				float DeltaTime = currentFrameStartTime - previousFrameStartTime;
				previousFrameStartTime = currentFrameStartTime;

				HandleWindowEvent();
				Tick(DeltaTime);
			}
		}
	}

	void Application::HandleWindowEvent()
	{
		sf::Event event;
		while (m_window->pollEvent(event))
		{
			//handle window close event
			if (event.type == sf::Event::Closed)
			{
				m_window->close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				HandleInput();
			}
		}
	}

	void Application::BeginPlay()
	{
		if (m_currentLevel)
		{
			m_currentLevel->BeginPlay();
		}
	}

	void Application::Tick(float DeltaTime)
	{
		if (m_currentLevel)
		{
			m_currentLevel->Tick(DeltaTime);
		}
		m_window->clear();
		m_currentLevel->Draw();
		m_window->display();
	}

	void Application::LoadLevel(Level* level)
	{
		if (m_currentLevel)
		{
			delete m_currentLevel;
		}
		m_currentLevel = level;

		Run();
	}
	void Application::HandleInput()
	{
		if (m_currentLevel)
		{
			m_currentLevel->HandleInput();
		}
	}
	void Application::AddScore()
	{
		m_score++; 
		std::cout << m_score << std::endl;

		if (m_score > m_highScore)
		{
			m_highScore = m_score;
			std::cout << "You pass high score!" << std::endl;
		}
	}
}