#include "Pipe.h"

Pipe::Pipe(ty::Level* level)
	:Entity(level)
{
	SetVisualTexture("Pipe.png");
	MovementComp = ConstructEntityComp<ty::MovementComp>();
	MovementComp->SetVel(sf::Vector2f(-80.f, 0.f));
	SetPosition(GetWindowWidth() / 2, GetWindowHeight() / 2);

	m_CollisionComp = ConstructEntityComp<ty::CollisionComp>();
}

void Pipe::Tick(float DeltaTime)
{
	Entity::Tick(DeltaTime);
	if (GetPositionX() < -GetBounds().width)
	{
		Destroy();
	}
}
