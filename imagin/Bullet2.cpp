#include "Bullet2.h"
#include"DxLib.h"
#include"GameScene.h"

Bullet2::Bullet2(Vec2d pos, double theta, bool rotate) :BulletBase(pos) {
	center = pos;
	this->theta = theta;
	omega_r = (rotate ? 1 : -1) * 0.01 / DX_PI;
	verI = Vec2d(0, 1);
}

void Bullet2::Update() {
	if (GameScene::GetReality()) {
		if (radius < 100) {
			radius += 5;
		}
		else if(radius<250){
			radius += 1;
		}
		else {
			radius += 0.5;
		}
		theta += omega_r;
		SetPos(center + Vec2d(radius * cos(theta), radius * sin(theta)));
	}
	else {
		center += verI;
		SetPos(pos + verI);
	}


	count++;
}

void Bullet2::Draw() {
	if (BulletBase::isinArea() == false) {
		return;
	}
	if (GameScene::GetReality()) {
		DrawCircleAA(pos.GetX(), pos.GetY(), r, 32, GetColor(100, 200, 0));
	}
	else {
		DrawCircleAA(pos.GetX(), pos.GetY(), r, 32, GetColor(200, 100, 0));
	}
}

bool Bullet2::isinArea() {
	if (radius > 1000) {
		return false;
	}
	else {
		return true;
	}
}