/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "dungeonLevel.h"
#include "player.h"
#include "enemy.h"

DungeonLevel::DungeonLevel() : Scene() {
	Player* player = new Player();
	

	this->addChild(player);

	Enemy* enemy = new Enemy(std::vector<Vector2> {Vector2(100, 100), Vector2(300, 300), Vector2(500, 200)});

	enemy->position = Vector2(200, 200);

	this->addChild(enemy);
}


DungeonLevel::~DungeonLevel() {
}

void DungeonLevel::update(float deltaTime) {

}
