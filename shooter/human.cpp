/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "human.h"

void Human::OnDeath() {
	//Remove us from parent
	this->parent()->removeChild(this);

	//Delete instance
	delete this;
}

Human::Human() : Entity() {
	this->health = HUMAN_MAX_HEALTH_VALUE;

	this->addSprite("assets/square.tga");
	this->sprite()->color = RED;
}

int Human::GetHealth() {
	return this->health;
}

void Human::Heal(int amount) {
	this->health += amount;

	if (this->health > HUMAN_MAX_HEALTH_VALUE) {
		this->health = HUMAN_MAX_HEALTH_VALUE;
	}

}

void Human::Damage(int amount) {
	this->health -= amount;

	if (this->health < 0) {
		//Let human die
		this->OnDeath();
	}
}

Human::~Human() {

}

void Human::update(float deltaTime) {

}
