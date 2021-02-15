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
		}
		//TODO: Handle Input event
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
}