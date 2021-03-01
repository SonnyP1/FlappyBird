#include "Bird.h"
#include <type_traits>
#include <typeinfo>
#include <iostream>
#include "Pipe.h"
#include "Medal.h"
#include "FlappyBirdApp.h"
#include "GameoverLevel.h"
Bird::Bird(ty::Level* level)
	:Entity(level)
{
	SetVisualTexture("bird.png");
	SetPosition(GetWindowWidth() / 4, GetWindowHeight() / 2);

	PhysicComp = ConstructEntityComp<ty::PhysicsMovementComp>();
	m_CollisionComp = ConstructEntityComp<ty::CollisionComp>();
}

void Bird::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		PhysicComp->SetVel(sf::Vector2f(PhysicComp->GetVel().x, -400.f));
	}
}

void Bird::OnCollisionEnter(ty::Entity* otherEntity)
{
	//std::cout << typeid(*otherEntity).name() << std::endl;
	//std::cout << typeid(Pipe).name() << std::endl;

	if (otherEntity && typeid(*otherEntity) == typeid(Pipe))
	{
		std::cout << "I HIT PIPE" << std::endl;
		GetApp()->LoadLevel(new GameoverLevel(GetApp()));
	}
	if ( otherEntity && typeid(*otherEntity) == typeid(Medal))
	{
		std::cout << "I HIT MEDAL" << std::endl;
		GetApp()->AddScore();
		otherEntity->Destroy();
	}
}
