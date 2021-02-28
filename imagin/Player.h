#pragma once
#include"Object.h"

class Player : public Object {
private:
	const double V = 5;

	int invinciblecount=0;
public:
	bool isInvincible = false;
	Player();

	void Draw();
	void Update();
};