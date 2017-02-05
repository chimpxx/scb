#pragma once
#include "PhysicsEntity.h"

class Player : public PhysicsEntity
{
public:
	Player(PhysicsEntity* physicsBody);
	~Player();

	void runRight();
	void runLeft();
	void jump();

	void update(float deltaTime);

private:
	void updatePhysics();

public:

private:
	glm::vec3 prevPosition;
	b2Vec2 b2Direction;
	float speed;
};

