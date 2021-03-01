#pragma once
#include "Entity.h"
#include "PhysicsMovementComp.h"
#include "CollsionComp.h"
class Bird : public ty::Entity
{
public:
	Bird(class ty::Level* level);
	virtual void HandleInput() override;
	virtual void OnCollisionEnter(class ty::Entity* entity) override;
private:
	ty::PhysicsMovementComp* PhysicComp;
	ty::CollisionComp* m_CollisionComp;
};