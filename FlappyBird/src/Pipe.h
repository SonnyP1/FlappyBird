#pragma once
#include "Entity.h"
#include "MovementComp.h"
#include "CollsionComp.h"
class Pipe :public ty::Entity {
public:
	Pipe(class ty::Level* level);
	ty::MovementComp* MovementComp;
	virtual void Tick(float DeltaTime) override;
private:
	ty::CollisionComp* m_CollisionComp;
};