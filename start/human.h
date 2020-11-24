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

/// @brief The MyEntity class is the Entity implementation.
class Human : public Entity {
public:
	/// @brief Constructor
	Human();
	/// @brief Destructor
	virtual ~Human();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* HUMAN_H */
