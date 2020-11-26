/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "dungeonLevel.h"
#include "player.h"

DungeonLevel::DungeonLevel() : Scene() {
	Player* player = new Player();
	
	this->addChild(player);
}


DungeonLevel::~DungeonLevel() {
}

void DungeonLevel::update(float deltaTime) {

}
