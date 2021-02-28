#include "Stage1.h"
#include"Enemy1.h"
#include"DxLib.h"

#include"GameScene.h"

#include"Input.h"
#include"eScene.h"


Stage1::Stage1(BulletManager* bm):StageBase(bm){
	
};


void Stage1::Update() {
	_em->Update();
	
	if (count == 30) {
		_em->Add(std::make_shared<Enemy1>(Vec2d(GameSceneDefine::MARGIN+GameSceneDefine::PLAYAREA_WIDTH/2,200),_bm));
	}

	count++;
}

void Stage1::Draw() {
	//DrawFormatString(0, 100, GetColor(255, 255, 255), "count:%d", count);
	_em->Draw();
}