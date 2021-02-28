#include"Bullet1.h"
#include"DxLib.h"
#include"GameScene.h"

Bullet1::Bullet1(Vec2d pos) :BulletBase(pos) {
	
}

Bullet1::Bullet1(Vec2d pos, BulletManager* bm) : Bullet1(pos) {
	_bm = bm;
}

void Bullet1::Update() {
	if (GameScene::GetReality()) {
		SetPos(GetPos() + Vec2d(0, 5));
	}
	else {
		SetPos(GetPos() + Vec2d(5, 0));
	}
	count++;
}

void Bullet1::Draw() {
	if (GameScene::GetReality()) {
		DrawCircle(pos.GetX(), pos.GetY(), 10, GetColor(100, 200, 0));
	}
	else {
		DrawCircle(pos.GetX(), pos.GetY(), 10, GetColor(200, 100, 0));
	}
}