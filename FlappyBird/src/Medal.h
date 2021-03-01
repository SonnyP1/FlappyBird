#pragma once
#include "Entity.h"
#include "CollsionComp.h"
#include "MovementComp.h"
class Medal : public ty::Entity
{
public:
	Medal(class ty::Level* level);
	virtual void OnCollisionEnter(class ty::Entity* entity) override;
private:
	ty::CollisionComp* m_CollisionComp;
	ty::MovementComp* m_MovementComp;
};