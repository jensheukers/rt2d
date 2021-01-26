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

//all world level objects
class DLObject : public Entity {
private:
	Sprite* tileMap;
	int tileMapIndex;
public:
	DLObject();

	virtual void update(float deltaTime) {};
};

class DungeonLevel : public Scene {
private:
	Sprite* tileMap;

	class Player* player;

	std::vector<class Pickup*> pickups; // All pickups in the level
	std::vector<class Enemy*> enemies; // All enemies in the level
public:

	DungeonLevel();
	virtual ~DungeonLevel();
	virtual void update(float deltaTime);

	class Player* GetPlayer();

	class Player* CreatePlayer(Vector2 pos = Vector2(0,0)); // Safely create a player instance

	class Enemy* CreateEnemy(std::vector<Vector2> path, Vector2 pos = Vector2(0, 0), std::vector<class Human*> targetList = std::vector<class Human*>{});

	virtual void ConstructWorld();
};

#endif /* DUNGEONLEVEL_H */
