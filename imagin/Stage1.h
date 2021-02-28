#pragma once
#include"StageBase.h"

class Stage1 :public StageBase {
public:
	Stage1(BulletManager* bm);

	void Update();
	void Draw();
};