#include"DxLib.h"
#include"Enemy1.h"
#include<functional>

#include"Bullet1.h"
#include"Bullet2.h"

Enemy1::Enemy1(Vec2d pos, BulletManager* bm) :EnemyBase(pos, bm) {
	this->pos = pos;
	r = 10;
	center = pos;
}

void Enemy1::Update() {

	if (count % 60 == 1) {
		//_bm->Add(std::make_shared<BulletBase>(pos,move));
		//_bm->Add(std::make_shared<Bullet1>(pos));

		int way = 40;
		for (int i = 0; i < way; ++i) {
			_bm->Add(std::make_shared<Bullet2>(pos, i * 2.0 * DX_PI / way, true));
			_bm->Add(std::make_shared<Bullet2>(pos, i * 2.0 * DX_PI / way, false));

		}
	}

	SetPos(Vec2d(center.GetX() + 30 * cos(count * DX_PI / 67), center.GetY()));

	count++;
}

void Enemy1::Draw() {
	DrawCircleAA(pos.GetX(), pos.GetY(), r, 32, GetColor(200, 50, 30));
	//DrawFormatString(0, 100, GetColor(255, 255, 0), "\ncount:%d", count);
}