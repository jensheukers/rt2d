#ifndef PLAYER_H
#define PLAYER_H

#define PLAYER_SPEED 50

#include "human.h"

class Player : public Human {
private:
	float speed;

	virtual void OnDeath();


public:
	Player();

	virtual void update(float deltaTime);
	~Player();
};


#endif // !PLAYER_H