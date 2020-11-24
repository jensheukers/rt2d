/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @brief Description of My Awesome Game.
 *
 * @file main.cpp
 *
 * @mainpage My Awesome Game
 *
 * @section intro Introduction
 *
 * Detailed description of My Awesome Game.
 *
 * There's even a second paragraph.
 */
#include <rt2d/core.h>

#include "dungeonLevel.h"

/// @brief main entry point
int main( void )
{
	// Core instance
	Core core;


	DungeonLevel* level = new DungeonLevel();

	while(level->isRunning()) {
		core.run(level);
		core.showFrameRate(5); 
	}
	//core.cleanup(); 
	delete level;

	return 0;
}
