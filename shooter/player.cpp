#include "player.h"

void Player::OnDeath() {
	//Remove us from parent
	this->parent()->removeChild(this);

	//Delete instance
	delete this;
}

Player::Player() : Human() {
	this->speed = PLAYER_SPEED;
	this->scale = Vector2(0.5f, 0.5f);
}

void Player::update(float deltaTime) {

	//Handle Input
	if (input()->getKey(KeyCode::W)) {
		this->position += ((Vector2(0, -1) * deltaTime) * speed);
	}

	if (input()->getKey(KeyCode::S)) {
		this->position += ((Vector2(0, 1) * deltaTime) * speed);
	}

	if (input()->getKey(KeyCode::A)) {
		this->position += ((Vector2(-1, 0) * deltaTime) * speed);
	}

	if (input()->getKey(KeyCode::D)) {
		this->position += ((Vector2(1, 0) * deltaTime) * speed );
	}
}

Player::~Player() {

}