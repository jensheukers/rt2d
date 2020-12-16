#include "enemy.h"


Enemy::Enemy(std::vector<Vector2> path) {
	this->scale = Vector2(0.2f, 0.2f);
	this->path = path;
	this->pointRange = 5.f;
	this->speed = ENEMY_SPEED;

	this->nextPoint = this->path[0];

	this->weapon = new Weapon();
	this->addChild(weapon);
}

void Enemy::update(float deltaTime) {
	
	//handle our movement
	this->HandleMovement(deltaTime);

	if (input()->getKeyDown(KeyCode::G)) {
		ShootWeapon(targetList[0]);
	}
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

	ddClear();

	//Check for targets
	for (size_t i = 0; i < targetList.size(); i++) {
		if (CalculateDistance(targetList[i]->position, this->position) < ENEMY_SIGHT) {
			return;
		}
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

void Enemy::AddToTargetList(Human* human) {
	targetList.push_back(human);
}

void Enemy::RemoveFromTargetList(Human* human) {
	for (size_t i = 0; i < targetList.size(); i++) {
		if (targetList[i] == human) {
			targetList.erase(targetList.begin(), targetList.begin() + i);
		}
	}
}

//Assume enemy is child of scene
void Enemy::ShootWeapon(Human* target) {
	float dx = this->position.x - target->position.x;
	float dy = this->position.y - target->position.y;
	Vector2 direction = Vector2(target->position.x - this->position.x, target->position.y - this->position.y) / (float)sqrt(dx * dx + dy * dy);


	std::vector<Human*> trylist;

	for (size_t i = 0; i < parent()->children().size(); i++) {
		if (parent()->children()[i] != this && dynamic_cast<Human*>(parent()->children()[i])) {
			trylist.push_back(dynamic_cast<Human*>(parent()->children()[i]));
		}
	}

	weapon->Shoot(direction, trylist, parent());
}

Enemy::~Enemy() {
	delete weapon;
}