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

DLObject::DLObject() {

	this->addSprite("assets/level.tga");
	this->scale = Vector2(2.f, 2.f);

	//Split uv coords
}

DungeonLevel::DungeonLevel() : Scene() {
	this->ConstructWorld();

	tileMap = new Sprite();

	this->CreatePlayer(Vector2(32, 32));

	this->CreateEnemy(std::vector<Vector2> {Vector2(100, 100), Vector2(300, 100)}, Vector2(100, 100), std::vector<Human*> { player });
	this->CreateEnemy(std::vector<Vector2> {Vector2(900, 100), Vector2(900, 400), Vector2(900, 100), Vector2(500, 100)}, Vector2(500, 100), std::vector<Human*> { player });
	//this->CreateEnemy(std::vector<Vector2> {Vector2(100, 100), Vector2(300, 100), Vector2(500, 200)}, Vector2(400, 100), std::vector<Human*> { player });

	this->CreateEnemy(std::vector<Vector2> {Vector2(200, 400), Vector2(500, 400)}, Vector2(100, 400), std::vector<Human*> { player });

	/*ddLine(Point(100, 100), Point(300, 300), BLUE);
	ddLine(Point(300, 300), Point(500, 200), BLUE);
	ddLine(Point(500, 200), Point(100, 100), BLUE);*/
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

void DungeonLevel::ConstructWorld() {
	DLObject* obj = new DLObject();
	obj->position = Vector2(0, 0);
	obj->sprite()->pivot = Vector2(0,0);

	this->addChild(obj);
}