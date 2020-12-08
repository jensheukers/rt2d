#include "enemy.h"


Enemy::Enemy(std::vector<Vector2> path) {
	this->scale = Vector2(0.5f, 0.5f);
	this->path = path;
	this->pointRange = 5.f;
	this->speed = ENEMY_SPEED;
}

void Enemy::update(float deltaTime) {
	
	//handle our movement
	this->HandleMovement(deltaTime);
}

void Enemy::HandleMovement(float deltaTime) {
	static int _INDEX = 0;
	if (CalculateDistance(position, nextPoint) <= pointRange) {

		//Set next point
		if ((_INDEX = _INDEX + 1) >= path.size()) {
			_INDEX = 0;
		}

		nextPoint = path[_INDEX];
	}

	//Lerp between the points
	MoveToPoint(deltaTime);
}

float Enemy::CalculateDistance(Vector2 a, Vector2 b) {
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	return (float)sqrt(dx * dx + dy * dy);
}

void Enemy::MoveToPoint(float deltaTime) {
	Vector2 direction = Vector2(nextPoint.x - position.x, nextPoint.y - position.y) / CalculateDistance(position , nextPoint);


	this->position += (direction * speed) * deltaTime;
}