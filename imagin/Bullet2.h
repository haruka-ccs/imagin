#pragma once
#include "BulletBase.h"
class Bullet2 : public BulletBase{
private:
	Vec2d center;
	double radius = 0;
	double theta = 0;
	double omega_r = 0;
	double omega_i = 0;
	double r = 6;
public:
	Bullet2(Vec2d pos, double theta, bool rotate);
	void Update();
	void Draw();

	bool isinArea();
};

