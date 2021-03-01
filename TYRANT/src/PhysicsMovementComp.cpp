#include "PhysicsMovementComp.h"
#include "Entity.h"
#include <iostream>
void ty::PhysicsMovementComp::TickComp(float DeltaTime)
{
	MovementComp::TickComp(DeltaTime);
	SetVel(sf::Vector2f(GetVel().x, GetVel().y + m_Gravity * DeltaTime));
}
