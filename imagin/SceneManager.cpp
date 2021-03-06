#include"SceneManager.h"
#include"DxLib.h"
#include"Input.h"
#include"TitleScene.h"
#include"GameScene.h"
#include"Fade.h"
#include"Ease.h"
#include"ConfigScene.h"

SceneManager::SceneManager() :IOnSceneChangedListener(){
	sceneStack.push(std::make_shared<TitleScene>(this));
	fadeflag = false;
}

void SceneManager::Draw() {
	sceneStack.top()->Draw();
	if (fadeflag) {
		fade.Draw();
	}

	//DrawFormatString(0,200,fade.hard)
	//DrawFormatString(0, 100, GetColor(255, 255, 255), "fadeflag:%d", fadeflag);
	//DrawFormatString(0, 140, GetColor(255, 255, 255), "t_next:%s", ToString(t_next));
	//DrawFormatString(0, 180, GetColor(255, 255, 255), "t_clear:%d", t_clear);
}

void SceneManager::Update() {
	if (fadeflag == false) {
		sceneStack.top()->Update();
	}
	else {
		fade.Update();
		if (fade.CheckFinish() == true) {
			fadeflag = false;
		}
	}
}

//void SceneManager::onSceneChanged(eScene next, Param param, const bool clear, const bool fadeflag) {
//	t_clear = clear;
//	t_next = next;
//	if (fadeflag == true) {
//		this->fadeflag = true;
//		fade.Init();
//	}
//	else {
//		this->ProceedScene(param);
//	}
//}

void SceneManager::onSceneChanged(eScene next, const bool clear, const bool fadeflag) {
	t_clear = clear;
	t_next = next;
	if (fadeflag == true) {
		this->fadeflag = true;
		fade.Init();
	}
	else {
		this->ProceedScene();
	}
}

void SceneManager::BackScene() {
	sceneStack.pop();
}

void SceneManager::ProceedScene(){
	if (t_clear == true) {
		while (!sceneStack.empty()) {
			sceneStack.pop();
		}
	}
	switch (t_next) {
	case eScene::Title:
		sceneStack.push(std::make_shared<TitleScene>(this));
		break;
	case eScene::Game:
		//PlaySoundMem(Sound::Get().game_bgm, DX_PLAYTYPE_LOOP);
		sceneStack.push(std::make_shared<GameScene>(this));
		break;
	case eScene::GameOver:
		//sceneStack.push(std::make_shared<GameOverScene>(this));
		break;
	case eScene::Config:
		sceneStack.push(std::make_shared<ConfigScene>(this));
		break;
	case eScene::Clear:
		//sceneStack.push(std::make_shared<ClearScene>(this));
		break;
	default:
		//どうしようもないエラー発生
		break;
	}
}