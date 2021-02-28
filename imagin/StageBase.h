#pragma once
#include "EnemyManager.h"
#include "BulletManager.h"

class StageBase {
protected:
	EnemyManager* _em = new EnemyManager();
	BulletManager* _bm;
	long count = 0;

public:
	//StageBase() {};
	StageBase(BulletManager* bm) :_bm(bm) {};
	virtual void Update() {};
	virtual void Draw() {};
};