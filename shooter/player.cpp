#include "player.h"

void Player::OnDeath() {
	//Remove us from parent
	this->parent()->removeChild(this);

	//Delete instance
	delete this;
}

Player::Player() : Human() {
	this->speed = PLAYER_SPEED;
	this->scale = Vector2(0.2f, 0.2f);

	this->sprite()->color = GREEN;

	this->weapon = new Weapon();
	this->addChild(weapon);
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

	if (input()->getKeyDown(KeyCode::F)) {
		float dx = this->position.x - input()->getMouseX();
		float dy = this->position.y - input()->getMouseY();
		Vector2 direction = Vector2(input()->getMouseX() - this->position.x, input()->getMouseY() - this->position.y) / (float)sqrt(dx * dx + dy * dy);


		std::vector<Human*> trylist;

		for (size_t i = 0; i < parent()->children().size(); i++) {
			if (parent()->children()[i] != this && dynamic_cast<Human*>(parent()->children()[i])) {
				trylist.push_back(dynamic_cast<Human*>(parent()->children()[i]));
			}
		}

		weapon->Shoot(direction, trylist, parent());
	}
}

Player::~Player() {

}