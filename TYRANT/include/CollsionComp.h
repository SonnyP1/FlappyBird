#pragma once
#include "EntityComponent.h"
namespace ty {
	class TYRANT_API CollisionComp : public EntityComponent {
	public:
		CollisionComp(class Entity* entity) :EntityComponent(entity) {};
		virtual void TickComp(float DeltaTime) override;
	};
}