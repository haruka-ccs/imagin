#pragma once
#include"Vec2d.h"

class Object
{
protected:
	Vec2d pos;
	Vec2d verR;
	Vec2d verI;
	Vec2d accR;
	Vec2d accI;

	long count = 0;
	double r = 0;
public:
	Object();
	Object(Vec2d pos);
	void SetPos(Vec2d pos);
	void SetVerR(Vec2d ver);
	void SetVerI(Vec2d ver);
	void SetAccR(Vec2d acc);
	void SetAccI(Vec2d acc);

	Vec2d GetPos();
	Vec2d GetVerR();
	Vec2d GetVerI();
	Vec2d GetAccR();
	Vec2d GetAccI();

	long GetCount();
	double GetRadius();

	virtual void Draw() = 0;
	virtual void Update() = 0;

	virtual bool isinArea();

	void UpdatePosR();
	void UpdatePosI();
	void UpdateVerR();
	void UpdateVerI();

	void Init();
};

