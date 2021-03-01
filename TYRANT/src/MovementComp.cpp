#include "MovementComp.h"
#include "Entity.h"
#include <iostream>
namespace ty
{
	void MovementComp::TickComp(float DeltaTime)
	{
		GetEntity()->Move(m_Vel * DeltaTime);
	}
}
