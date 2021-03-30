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
	DrawString(0, 0, "Title", GetColor(255, 255, 255));
	//DrawFormatString(100, 100, GetColor(255, 255, 255), "\npadnum:%d", Input::Get().padNum);
	
	DrawString(800, 700, "Game Start", GetColor(255, 255, 255));
	DrawString(800, 730, "Config", GetColor(255, 255, 255));
	DrawString(800, 760, "Exit", GetColor(255, 255, 255));
	
	DrawString(780, 700 + menu.GetState() * 30, ">", GetColor(255, 255, 255));
}

void TitleScene::Update() {
	menu.Update();

	if (Input::Get().buttonstate[Button::A] == 1) {
		Param param;
		switch (menu.GetState())
		{
		case 0:
			param.Set("stage", 2);
			_implSceneChanged->onSceneChanged(eScene::Game, false, false);
			break;
		case 1:
			_implSceneChanged->onSceneChanged(eScene::Config, false, false);
			break;
		case 2:
			Input::Get().keystate[KEY_INPUT_ESCAPE] = 1;
			break;
		default:
			break;
		}
		++Input::Get().buttonstate[Button::A];
	}

	count++;
}