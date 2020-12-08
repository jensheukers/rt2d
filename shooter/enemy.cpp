#include "enemy.h"


Enemy::Enemy(std::vector<Vector2> path) {
	this->scale = Vector2(0.5f, 0.5f);
	this->path = path;
	this->pointRange = 5.f;
	this->speed = 1.f;
}

void Enemy::update(float deltaTime) {
	
	//handle our movement
	this->HandleMovement(deltaTime);
}

void Enemy::HandleMovement(float deltaTime) {
	static int _INDEX = 0;

	float dx = currentPoint.x - nextPoint.x;
	float dy = currentPoint.y - nextPoint.y;
	float distance = (float)sqrt(dx * dx + dy * dy);

	if (distance <= pointRange) {
		currentPoint = nextPoint;

		//Set next point
		if ((_INDEX = _INDEX + 1) >= path.size()) {
			_INDEX = 0;
		}

		nextPoint = path[_INDEX];
	}

	//Lerp between the points
	LerpToPoint(deltaTime);
}

void Enemy::LerpToPoint(float deltaTime) {
	static float _AMOUNT = 0.2f;

	if ((_AMOUNT = _AMOUNT + (speed * deltaTime)) > 1) {
		_AMOUNT = 0.f;
	}

	this->position =  nextPoint * _AMOUNT + currentPoint * (1.f - _AMOUNT);
}