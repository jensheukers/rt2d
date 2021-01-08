#ifndef ENEMY_H
#define ENEMY_H

#define ENEMY_SPEED 50
#define ENEMY_SIGHT 100
#define ENEMY_SHOOT_INTERVAL 2

#include <vector>

#include "human.h"
#include "weapon.h"

class Enemy : public Human {
private:
	std::vector<Vector2> path; /// @brief list of vectors that contain the path the enemy will walk, will loop throughout the game
	Vector2 currentPoint; // The current target vector we have walked to
	Vector2 nextPoint; // The current target vector we are walking towards
	float pointRange; // distance between enemy and point to trigger finalization
	float speed; // Speed


	Weapon* weapon;

	std::vector<Human*> targetList;
public:
	Enemy(std::vector<Vector2> path = std::vector<Vector2>());

	virtual void update(float deltaTime);

	void HandleMovement(float deltaTime);

	float CalculateDistance(Vector2 a, Vector2 b);

	void MoveToPoint(float deltaTime);

	void AddToTargetList(Human* human);
	void RemoveFromTargetList(Human* human);

	void ShootWeapon(Human* target);

	~Enemy();
};

#endif // !ENEMY_H