#pragma once
#include"Object.h"
#include<functional>
#include<memory>

class BulletManager;

class BulletBase :public Object {
protected:
	BulletManager* _bm;
public:
	BulletBase(Vec2d pos);
	BulletBase(Vec2d pos, BulletManager* bm);

	virtual void Update();
	virtual void Draw();

	virtual bool isinArea();

	void Add(std::shared_ptr<BulletBase> b);
};