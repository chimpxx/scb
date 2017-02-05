#include "PhysicsEntity.h"



PhysicsEntity::PhysicsEntity(Entity* entity, b2Body* box2DBody)
	:Entity(*entity)
	,box2DBody(box2DBody)
{
}


PhysicsEntity::~PhysicsEntity()
{
}
