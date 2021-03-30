#include "GameScene.h"
#include "DxLib.h"
#include "Input.h"
#include "eScene.h"

#include"Stage1.h"
#include"Stage2.h"

GameScene::GameScene(IOnSceneChangedListener* _impl) :SceneBase(_impl) {
	stage = new Stage1(_bm);
	isReality = true;
	maskHandle = LoadMask("mask.png");
}

GameScene::GameScene(IOnSceneChangedListener* _impl, Param param) :GameScene(_impl){
	switch (param.Get("stage"))
	{
	case 1:
		stage = new Stage1(_bm);
		break;
	case 2:
		stage = new Stage2(_bm);
		break;
	default:
		break;
	}
}

bool GameScene::isReality = true;

void GameScene::Draw() {
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "\n\ngame");

	//DrawFormatString(0, 0, GetColor(255, 255, 255), "\n\n\nis real:%d", isReality);
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "\n\n\n\nsize:%d", _bm->GetSize());

	int white = GetColor(255, 255, 255);

	//TODO
	//毎フレームcreate/deleteするのは多分間違ってるのでマスク画像を張り替える形にする
	int maskScreen = CreateMaskScreen();
	DrawMask(0, 0, maskHandle, DX_MASKTRANS_NONE);

	stage->Draw();
	player.Draw();
	_bm->Draw();

	DeleteMaskScreen();

	DrawLineBox(GameSceneDefine::MARGIN, GameSceneDefine::MARGIN,
		GameSceneDefine::PLAYAREA_WIDTH + GameSceneDefine::MARGIN, GameSceneDefine::PLAYAREA_HEIGHT + GameSceneDefine::MARGIN,
		GetColor(255, 255, 255));

	DrawFormatString(900, 300, white, "被弾:%d", hitcount);

	if (pause == true) {
		DrawGraph(GameSceneDefine::MARGIN, GameSceneDefine::MARGIN, pauseScreen, FALSE);
		DrawString(300, 300, "Pause", white);
		DrawString(300, 400, "Resume", white);
		DrawString(300, 450, "Back to Title", white);
		DrawString(280, 400 + pauseMenu.GetState() * 50, ">", white);
	}
}

void GameScene::Update() {
	if (Input::Get().buttonstate[Button::START] == 1) {
		pause ^= 1;
		if (pause == true) {
			pauseScreen=MakeGraph(GameSceneDefine::PLAYAREA_WIDTH, GameSceneDefine::PLAYAREA_HEIGHT, TRUE);
			GetDrawScreenGraph(GameSceneDefine::MARGIN, GameSceneDefine::MARGIN,
				GameSceneDefine::PLAYAREA_WIDTH + GameSceneDefine::MARGIN, GameSceneDefine::PLAYAREA_HEIGHT + GameSceneDefine::MARGIN,  pauseScreen);
			GraphFilter(pauseScreen, DX_GRAPH_FILTER_GAUSS, 16, 1000);
			pauseMenu.SetState(0);
		}
	}

	if (pause == false) {
		if (Input::Get().buttonstate[Button::A] == 1) {
			ChangeReality();
		}

		stage->Update();
		player.Update();
		_bm->Update();

		Collision();
	}
	else {
		pauseMenu.Update();
		if (Input::Get().buttonstate[Button::A] == 1) {
			switch (pauseMenu.GetState())
			{
			case 0:
				pause = false;
				break;
			case 1:
				_implSceneChanged->onSceneChanged(eScene::Title, true, false);
			default:
				break;
			}
		}
	}
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