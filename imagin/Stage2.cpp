#include "Stage2.h"
#include"Enemy1.h"
#include"DxLib.h"

#include"GameScene.h"

#include"Input.h"
#include"eScene.h"


Stage2::Stage2(BulletManager* bm) :StageBase(bm) {

};


void Stage2::Update() {
	_em->Update();

	if (count == 30) {
		_em->Add(std::make_shared<Enemy1>(Vec2d(GameSceneDefine::MARGIN + GameSceneDefine::PLAYAREA_WIDTH / 2, 200), _bm));
	}

	count++;
}

void Stage2::Draw() {
	DrawFormatString(100, 100, GetColor(255, 255, 255), "stage 2", count);
	_em->Draw();
}