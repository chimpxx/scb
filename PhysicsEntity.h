#ifndef _PHYSICS_ENTITY_H_
#define _PHYSICS_ENTITY_H_

#include "Entity.h"
#include <Box2D/Box2D.h>
class PhysicsEntity : public Entity
{
public:
	PhysicsEntity(Entity* entity, b2Body* box2DBody);
	~PhysicsEntity();

protected:
	b2Body* box2DBody;
};

#endif // !_PHYSICS_ENTITY_H_

