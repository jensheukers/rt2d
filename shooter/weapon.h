#ifndef WEAPON_H
#define WEAPON_H

#include "entity.h"
#include "human.h"

#define PROJECTILE_SPEED 150.f
#define PROJECTILE_HIT_DIST 15.f
#define PROJECTILE_LIFE_LENGHT 1.f

class Projectile : public Entity {
private:
	Vector2 velocity;

	std::vector<Human*> tryList;

	float lifeTime;
public:
	int damage = 34;

	Projectile(Vector2 velocity, std::vector<Human*> tryList);

	void update(float deltaTime);

	void Destroy();
};


class Weapon : public Entity {
public:
	void Shoot(Vector2 direction, std::vector<Human*> tryList, Entity* scene);

	void update(float deltaTime) {};
};
#endif // !WEAPON_H