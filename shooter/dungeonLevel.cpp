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
	player->position = Vector2(250, 250);

	this->addChild(player);

	Enemy* enemy = new Enemy(std::vector<Vector2> {Vector2(100, 100), Vector2(300, 300), Vector2(500, 200)});
	enemy->AddToTargetList(player);

	ddLine(Point(100, 100), Point(300, 300), BLUE);
	ddLine(Point(300, 300), Point(500, 200), BLUE);
	ddLine(Point(500, 200), Point(100, 100), BLUE);

	this->addChild(enemy);
}


DungeonLevel::~DungeonLevel() {
}

void DungeonLevel::update(float deltaTime) {

}
