#include"TitleScene.h"
#include"DxLib.h"
#include"eScene.h"
#include"SceneManager.h"
#include"Input.h"
//#include"Image.h"
#include<math.h>
#include"Ease.h"
//#include"Sound.h"

TitleScene::TitleScene(IOnSceneChangedListener* impl) :SceneBase(impl) {

}

void TitleScene::Draw() {

}

void TitleScene::Update() {
	count++;
	if (Input::Get().keystate[KEY_INPUT_SPACE] >0) {
		//PlaySoundMem(Sound::Get().title_to_game, DX_PLAYTYPE_BACK);
		_implSceneChanged->onSceneChanged(eScene::Game, false, false);
	}

}