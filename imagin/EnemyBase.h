#pragma once
#include "Object.h"
#include "BulletManager.h"

class EnemyBase :public Object {
protected:
	BulletManager* _bm;
public:
	EnemyBase(Vec2d pos, BulletManager* bm);

	virtual void Update();
	virtual void Draw();
};