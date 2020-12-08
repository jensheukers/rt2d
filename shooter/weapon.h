#ifndef WEAPON_H
#define WEAPON_H
#include "entity.h"

#define PROJECTILE_SPEED 25.f

class Projectile : public Entity {
private:
	Vector2 velocity;
public:
	Projectile(Vector2 velocity);

	void update(float deltaTime);
};


class Weapon : public Entity {
public:
	void Shoot(Entity* scene);

	void update(float deltaTime) {};
};
#endif // !WEAPON_H