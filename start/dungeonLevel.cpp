/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "dungeonLevel.h"

DungeonLevel::DungeonLevel() : Scene() {
	Human* testHuman = new Human();
	
	this->addChild(testHuman);
}


DungeonLevel::~DungeonLevel() {
}

void DungeonLevel::update(float deltaTime) {

}
