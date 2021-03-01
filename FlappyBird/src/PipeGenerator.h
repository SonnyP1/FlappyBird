#pragma once
#include "Entity.h"
class PipeGenerator : public ty::Entity {
public:
	PipeGenerator(class ty::Level* level);
	virtual void Tick(float DeltaTime) override;
private:
	void SpawnPipe();
private:
	float m_SpawnInterval;
	sf::Clock m_SpawnerTimer;
};