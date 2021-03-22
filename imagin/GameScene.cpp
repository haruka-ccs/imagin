#include "GameScene.h"
#include "DxLib.h"
#include "Input.h"
#include "eScene.h"

#include"Stage1.h"

GameScene::GameScene(IOnSceneChangedListener* _impl) :SceneBase(_impl) {
	stage = new Stage1(_bm);
	isReality = true;
}

bool GameScene::isReality = true;

void GameScene::Draw() {
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "\n\ngame");

	//DrawFormatString(0, 0, GetColor(255, 255, 255), "\n\n\nis real:%d", isReality);
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "\n\n\n\nsize:%d", _bm->GetSize());

	DrawLineBox(GameSceneDefine::MARGIN, GameSceneDefine::MARGIN,
		GameSceneDefine::PLAYAREA_WIDTH + GameSceneDefine::MARGIN, GameSceneDefine::PLAYAREA_HEIGHT + GameSceneDefine::MARGIN,
		GetColor(255, 255, 255));

	DrawFormatString(900, 300, GetColor(255, 255, 255), "”í’e:%d", hitcount);

	stage->Draw();
	player.Draw();
	_bm->Draw();
}

void GameScene::Update() {
	if (Input::Get().buttonstate[Button::A] == 1) {
		ChangeReality();
	}

	stage->Update();
	player.Update();
	_bm->Update();

	Collision();
}

void GameScene::Collision() {
	if (player.isInvincible == true) {
		return;
	}
	if (_bm->Collision(player)) {
		player.isInvincible = true;
		++hitcount;
	}
}

void GameScene::SetReality(bool flag) {
	isReality = flag;
}

void GameScene::ChangeReality() {
	isReality ^= 1;
}

bool GameScene::GetReality() {
	return isReality;
}