/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H

#include <rt2d/scene.h>

class DungeonLevel : public Scene {
private:
	Sprite* tileMap;
public:

	DungeonLevel();
	virtual ~DungeonLevel();
	virtual void update(float deltaTime);
};

#endif /* DUNGEONLEVEL_H */
