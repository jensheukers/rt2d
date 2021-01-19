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

Projectile* Weapon::Shoot(Vector2 direction, std::vector<Human*> tryList, Entity* scene) {
	//Spawn projectile
	Projectile* projectile = new Projectile(direction, tryList);
	projectile->position = this->parent()->position;
	scene->addChild(projectile);

	return projectile;
}