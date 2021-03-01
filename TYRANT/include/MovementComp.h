#pragma once
#include "TyrantCore.h"
#include "EntityComponent.h"
#include <SFML/Graphics.hpp>
namespace ty {
	class TYRANT_API MovementComp :public EntityComponent
	{
	public:
		MovementComp(class Entity* entity) :EntityComponent(entity) {}
		virtual void TickComp(float DeltaTime) override;
		void SetVel(const sf::Vector2f& vel) { m_Vel = vel; }
		const sf::Vector2f GetVel() const { return m_Vel; }
	private:
		sf::Vector2f m_Vel;
	};
}