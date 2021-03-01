#include "CollsionComp.h"
#include "Entity.h"
void ty::CollisionComp::TickComp(float DeltaTime)
{
	auto& Entities = GetEntity()->GetLevel()->GetEntities();
	for (int i = 0; i < Entities.size(); i++)
	{
		sf::FloatRect OwnerBound = GetEntity()->GetBounds();
		sf::FloatRect OtherBound = Entities[i]->GetBounds();
		if (OwnerBound.intersects(OtherBound) && Entities[i].get() != GetEntity())
		{
			GetEntity()->OnCollisionEnter(Entities[i].get());
		}
	}
}
