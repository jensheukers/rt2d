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
	tileMap = new Sprite();

	Player* player = new Player();
	player->position = Vector2(250, 250);

	this->addChild(player);

	{
		Enemy* enemy = new Enemy(std::vector<Vector2> {Vector2(100, 100), Vector2(300, 300), Vector2(500, 200)});
		enemy->AddToTargetList(player);
		this->addChild(enemy);

		Enemy* enemy2 = new Enemy(std::vector<Vector2> {Vector2(700, 300), Vector2(200, 300), Vector2(500, 400)});
		enemy2->AddToTargetList(player);
		this->addChild(enemy2);

		enemy2->AddToTargetList(enemy);

		ddLine(Point(700, 300), Point(200, 300), BLUE);
		ddLine(Point(200, 300), Point(500, 400), BLUE);
		ddLine(Point(500, 400), Point(700, 300), BLUE);



	}
}


DungeonLevel::~DungeonLevel() {
	delete tileMap;
}

void DungeonLevel::update(float deltaTime) {

}
