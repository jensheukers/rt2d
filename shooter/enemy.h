#ifndef ENEMY_H
#define ENEMY_H

#include <vector>

#include "human.h"

class Enemy : public Human {
private:
	std::vector<Vector2> path; /// @brief list of vectors that contain the path the enemy will walk, will loop throughout the game
	Vector2 currentPoint; // The current target vector we have walked to
	Vector2 nextPoint; // The current target vector we are walking towards
	float pointRange; // distance between enemy and point to trigger finalization
	float speed; // Speed
public:
	Enemy(std::vector<Vector2> path = std::vector<Vector2>());

	virtual void update(float deltaTime);

	void HandleMovement(float deltaTime);

	void LerpToPoint(float deltaTime);
};

#endif // !ENEMY_H