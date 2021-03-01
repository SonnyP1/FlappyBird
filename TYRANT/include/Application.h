#pragma once
#include <TyrantCore.h>
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

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
		void HandleInput();
		sf::RenderWindow* GetWindow(){ return m_window; }
		const sf::RenderWindow* GetWindow()const{ return m_window; }

		void AddScore();
		int GetScore() { return m_score; }
		void ResetScore() { m_score = 0; }
		int GetHighScore() { return m_highScore; }
	private:
		sf::RenderWindow* m_window;
		class Level* m_currentLevel;
		sf::Clock m_Clock;
		int m_score;
		int m_highScore;
	};
}