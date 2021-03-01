#pragma once
//need m_Vel DeltaTime Gravity
#include "MovementComp.h"
namespace ty {
	class TYRANT_API PhysicsMovementComp : public MovementComp
	{
	public:
		PhysicsMovementComp(class Entity* entity) : MovementComp(entity) {}
		virtual void TickComp(float DeltaTime) override;
	private:
		float m_Gravity = 980.f;
	};
}