#include "EnemyBase.h"
#include "DxLib.h"

EnemyBase::EnemyBase(Vec2d pos, BulletManager* bm) :_bm(bm) {
	this->pos = pos;
};

void EnemyBase::Update() {

}

void EnemyBase::Draw() {
	DrawCircle(pos.GetX(), pos.GetY(), 10, GetColor(255, 0, 0));
}