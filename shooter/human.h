/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef HUMAN_H
#define HUMAN_H

#include <rt2d/entity.h>

#define HUMAN_MAX_HEALTH_VALUE 100

class Human : public Entity {
private:
	int health;


	virtual void OnDeath();

public:
	Human();

	int GetHealth();

	void Heal(int amount);

	void Damage(int amount);

	virtual ~Human();

	virtual void update(float deltaTime);
};

#endif /* HUMAN_H */
