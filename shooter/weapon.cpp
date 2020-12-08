#include "weapon.h"

Projectile::Projectile(Vector2 velocity) {
	this->velocity = velocity;

	this->addSprite("assets/square.tga");
	this->sprite()->color = GREEN;
	this->scale = Vector2(0.1, 0.1);
}

void Projectile::update(float deltaTime) {
	position += (velocity * PROJECTILE_SPEED) * deltaTime;
}

void Weapon::Shoot(Entity* scene) {
	float dx = this->parent()->position.x - input()->getMouseX();
	float dy = this->parent()->position.y - input()->getMouseY();
	Vector2 direction = Vector2(input()->getMouseX() - this->parent()->position.x, input()->getMouseY() - this->parent()->position.y) / (float)sqrt(dx * dx + dy * dy);

	//Spawn projectile
	Projectile* projectile = new Projectile(direction);
	projectile->position = this->parent()->position;
	scene->addChild(projectile);
}