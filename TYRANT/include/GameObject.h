#pragma once
#include "TyrantCore.h"
#include "Level.h"
#include <SFML/Graphics.hpp>

namespace ty {
	class TYRANT_API GameObject {
	public:
		GameObject(class Level* level) :m_Level(level) {};

		class Level* GetLevel() { return m_Level; }
		class Application* GetApp() { return m_Level->GetApp(); }
		sf::RenderWindow* GetWindow() { return m_Level->GetWindow(); }
		const sf::RenderWindow* GetWindow() const { return m_Level->GetWindow(); }
		sf::Vector2f GetWindowSize() const { return sf::Vector2f(GetWindow()->getSize().x,GetWindow()->getSize().y); }
		float GetWindowWidth() const { return GetWindowSize().x; }
		float GetWindowHeight() const { return GetWindowSize().y; }
		const sf::Texture& LoadTextures(const std::string& Dir)  {return GetLevel()->LoadTexture(Dir);};

	private:
		class Level* m_Level;

	};
}