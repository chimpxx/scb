#include "Player.h"



Player::Player(PhysicsEntity* physicsBody)
	:PhysicsEntity(*physicsBody)
{
    prevPosition = position;
	b2Direction.x = 0.0f;
	b2Direction.y = 0.0f;
	box2DBody->SetLinearVelocity(b2Direction);
	speed = 0.03f;
}


Player::~Player()
{
}

void Player::update(float deltaTime) {
	updatePhysics();
    prevPosition = position;
	position.x = box2DBody->GetPosition().x;
	position.y = box2DBody->GetPosition().y;
	matrixUpdated = false;
}

void Player::updatePhysics() {
	b2Direction.x = box2DBody->GetLinearVelocity().x;
	b2Direction.y = box2DBody->GetLinearVelocity().y;
}

void Player::runRight() {
	b2Direction = box2DBody->GetLinearVelocity();
	b2Direction.x = speed;
	
	//box2DBody->ApplyForce(b2Vec2(10.f, 0.0f), box2DBody->GetWorldCenter(), true);
    box2DBody->SetLinearVelocity(b2Vec2(5.0f, 0.0f));
}

void Player::runLeft() {
	b2Direction = box2DBody->GetLinearVelocity();
    b2Direction.x = -speed;

    //box2DBody->ApplyForce(b2Vec2(-10.f, 0.0f), box2DBody->GetWorldCenter(), true);
    box2DBody->SetLinearVelocity(b2Vec2(-5.0f, 0.0f));
}

void Player::jump() {

    //box2DBody->ApplyForce(b2Vec2(0.0f, 50.0f), box2DBody->GetWorldCenter(), true);
    box2DBody->SetLinearVelocity(b2Vec2(0.0f, 5.0f));
}

void Player::turnRight() {
    box2DBody->ApplyForceToCenter(b2Vec2(5.0f, 0.0f), true);
}

void Player::turnLeft() {
    box2DBody->ApplyForceToCenter(b2Vec2(-5.0f, 0.0f), true);
}
