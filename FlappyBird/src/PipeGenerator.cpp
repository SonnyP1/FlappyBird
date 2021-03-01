#include "PipeGenerator.h"
#include "Level.h"
#include "Pipe.h"
#include "Medal.h"
#include <iostream>
#include <random>
#include <ctime>
PipeGenerator::PipeGenerator(ty::Level* level)
	:Entity(level),m_SpawnInterval(2.f),m_SpawnerTimer()
{
	SetVisibility(false);
	srand(time(nullptr));
}

void PipeGenerator::Tick(float DeltaTime)
{
	Entity::Tick(DeltaTime);
	if (m_SpawnerTimer.getElapsedTime().asSeconds() >= m_SpawnInterval)
	{
		m_SpawnerTimer.restart();
		SpawnPipe();
		m_SpawnInterval = (3 + rand() % (6 - 3))*2;
	}
}

void PipeGenerator::SpawnPipe()
{

	std::cout << "Spawn Pipe" << std::endl;
	//Spawn 2 pipe
	std::shared_ptr<Pipe> TopPipe(new Pipe(GetLevel()));
	std::shared_ptr<Pipe> BottomPipe(new Pipe(GetLevel()));
	std::shared_ptr<Medal> MainMedal(new Medal(GetLevel()));
		//std::shared_ptr<Score> MiddleScore(new Score(GetLevel()));

	float PosX = GetWindowWidth();
	TopPipe->SetRotation(180.f);
	float TopPosY = 100 + rand() % (300 - 100);
	TopPipe->SetPosition(PosX + TopPipe->GetBounds().width, TopPosY);
	float Gap = 300 + rand() % (600 - 100);
	BottomPipe->SetPosition(PosX,TopPipe->GetPositionY()+ Gap);
	MainMedal->SetPosition(PosX, Gap);


	GetLevel()->AddEntity(TopPipe);
	GetLevel()->AddEntity(MainMedal);
	GetLevel()->AddEntity(BottomPipe);
}
