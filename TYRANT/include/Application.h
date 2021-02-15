#pragma once
#include <TyrantCore.h>
#include <string>
#include <SFML/Graphics.hpp>

namespace ty
{
	class TYRANT_API Application
	{
	public:
		Application(int width, int height, const std::string& title);
		virtual ~Application();
		virtual void Run();
		void HandleWindowEvent();
		virtual void BeginPlay();
		virtual void Tick(float DeltaTime);
		virtual void LoadLevel(class Level* level);
		sf::RenderWindow* GetWindow(){ return m_window; }
	private:
		sf::RenderWindow* m_window;
		class Level* m_currentLevel;
		sf::Clock m_Clock;
	};
}