#include "..\include\Entity.h"
#include "Entity.h"
#include "EntityComponent.h"
#include <iostream>
namespace ty {
	Entity::~Entity()
	{
		std::cout << "ENTITES DESTROY" << std::endl;
	}
	void Entity::SetVisualTexture(const std::string& Dir)
	{
		m_Visual.setTexture(GetLevel()->LoadTexture(Dir));
	}

	void Entity::HandleInput()
	{
	}

	void Entity::OnCollisionEnter(Entity* Other)
	{
	}

	void Entity::SetVisibility(bool Visible)
	{
		if (!Visible)
		{
			m_Visual.setColor(sf::Color::Transparent);
		}
		else
		{
			m_Visual.setColor(sf::Color::White);
		}
	}

	void Entity::Tick(float DeltaTime)
	{
		TickComponent(DeltaTime);
	}

	void Entity::TickComponent(float DeltaTime)
	{
		for (int i = 0; i < m_Component.size(); ++i)
		{
			m_Component[i]->TickComp(DeltaTime);
		}
	}
	void Entity::Destroy()
	{
		GetLevel()->AddPendingKillEntity(this);
	}
}