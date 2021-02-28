#include "BulletBase.h"
#include "DxLib.h"

#include"BulletManager.h"

#include"GameScene.h"

BulletBase::BulletBase(Vec2d pos) {
	this->pos = pos;
	_bm = new BulletManager();
}

BulletBase::BulletBase(Vec2d pos, BulletManager* bm) :BulletBase(pos) {
	_bm = bm;
}

void BulletBase::Draw() {
	if (GameScene::GetReality()) {
		DrawCircle(pos.GetX(), pos.GetY(), 10, GetColor(100, 200, 100));
	}
	else {
		DrawCircle(pos.GetX(), pos.GetY(), 10, GetColor(200, 100, 200));
	}
}

void BulletBase::Update() {
	count++;
}

void BulletBase::Add(std::shared_ptr<BulletBase> b) {
	_bm->Add(b);
}

bool BulletBase::isinArea() {
	if (pos.GetX() < GameSceneDefine::MARGIN ||
		(int)pos.GetX() > GameSceneDefine::PLAYAREA_WIDTH + GameSceneDefine::MARGIN ||
		pos.GetY() < GameSceneDefine::MARGIN ||
		(int)pos.GetY() > GameSceneDefine::PLAYAREA_HEIGHT + GameSceneDefine::MARGIN) {
		return false;
	}
	else {
		return true;
	}
}