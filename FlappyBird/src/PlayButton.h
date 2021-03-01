#pragma once
#include "Entity.h"
class PlayButton : public ty::Entity
{
public:
	PlayButton(class ty::Level* level);
	virtual void HandleInput() override;
};