#include "Medal.h"
#include "Bird.h"
#include <iostream>
Medal::Medal(ty::Level* level)
	:Entity(level)
{
	SetVisualTexture("GoldMedal.png");
	m_MovementComp = ConstructEntityComp<ty::MovementComp>();
	m_MovementComp->SetVel(sf::Vector2f(-80.f, 0.f));

	m_CollisionComp = ConstructEntityComp<ty::CollisionComp>();
}

void Medal::OnCollisionEnter(ty::Entity* otherEntity)
{

}
