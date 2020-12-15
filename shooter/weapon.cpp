#include "weapon.h"

Projectile::Projectile(Vector2 velocity, std::vector<Human*> tryList) {
	this->velocity = velocity;

	this->addSprite("assets/square.tga");
	this->sprite()->color = GREEN;
	this->scale = Vector2(0.1, 0.1);
	this->tryList = tryList;
	this->lifeTime = PROJECTILE_LIFE_LENGHT;
}

void Projectile::update(float deltaTime) {
	position += (velocity * PROJECTILE_SPEED) * deltaTime;

	//Check for collision with other entities
	for (size_t i = 0; i < tryList.size(); i++) {
		float dx = this->position.x - tryList[i]->position.x;
		float dy = this->position.y - tryList[i]->position.y;
		float distance = (float)sqrt(dx * dx + dy * dy);

		if (distance < PROJECTILE_HIT_DIST) {
			tryList[i]->Damage(damage);
			Destroy();
			return;
		}
	}

	this->lifeTime -= deltaTime;

	if (this->lifeTime < 0) {
		Destroy();
	}
}

void Projectile::Destroy() {
	parent()->removeChild(this);

	delete this;
}

void Weapon::Shoot(Entity* scene) {
	float dx = this->parent()->position.x - input()->getMouseX();
	float dy = this->parent()->position.y - input()->getMouseY();
	Vector2 direction = Vector2(input()->getMouseX() - this->parent()->position.x, input()->getMouseY() - this->parent()->position.y) / (float)sqrt(dx * dx + dy * dy);

	//Spawn projectile
	std::vector<Human*> trylist;

	for (size_t i = 0; i < scene->children().size(); i++) {
		if (scene->children()[i] != this->parent() && dynamic_cast<Human*>(scene->children()[i])) {
			trylist.push_back(dynamic_cast<Human*>(scene->children()[i]));
		}
	}


	Projectile* projectile = new Projectile(direction, trylist);
	projectile->position = this->parent()->position;
	scene->addChild(projectile);
}