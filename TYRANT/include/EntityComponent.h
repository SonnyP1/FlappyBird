#pragma once
#include "TyrantCore.h"
namespace ty {
	//pure virtual class meaning it is abstract. you cannot create an instance of a pure virtual class
	class TYRANT_API EntityComponent {
	public:
		EntityComponent(class Entity* entity) : m_Entity(entity) {};
		//pure virtual
		virtual void TickComp(float DeltaTime) = 0;
		class Entity* GetEntity() { return m_Entity; }
	private:
		class Entity* m_Entity;
	};
}