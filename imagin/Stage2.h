#pragma once
#include"StageBase.h"

class Stage2 :public StageBase {
public:
	Stage2(BulletManager* bm);

	void Update();
	void Draw();
};