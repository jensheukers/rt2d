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

	this->CreatePlayer(Vector2(0, 0));
	this->CreateEnemy(std::vector<Vector2> {Vector2(100, 100), Vector2(300, 300), Vector2(500, 200)}, Vector2(400, 100), std::vector<Human*> { player });

	ddLine(Point(100, 100), Point(300, 300), BLUE);
	ddLine(Point(300, 300), Point(500, 200), BLUE);
	ddLine(Point(500, 200), Point(100, 100), BLUE);
}


DungeonLevel::~DungeonLevel() {
	delete tileMap;
}

void DungeonLevel::update(float deltaTime) {

}

Player* DungeonLevel::GetPlayer() {
	return this->player;
}

Player* DungeonLevel::CreatePlayer(Vector2 pos) {
	player = new Player();
	
	player->position = pos;

	this->addChild(player);

	return player;
}

Enemy* DungeonLevel::CreateEnemy(std::vector<Vector2> path, Vector2 pos, std::vector<class Human*> targetList) {
	Enemy* enemy;
	enemy = new Enemy(path);
	enemy->position = pos;
		
	for (size_t i = 0; i < targetList.size(); i++) {
		enemy->AddToTargetList(targetList[i]);
	}

	this->addChild(enemy);

	return enemy;

}