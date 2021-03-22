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
	
	DrawString(800 - (menu.GetState() == 0 ? 20:0), 700, "Game Start", GetColor(255, 255, 255));
	DrawString(800 - (menu.GetState() == 1 ? 20:0), 700, "\nConfig", GetColor(255, 255, 255));
	DrawString(800 - (menu.GetState() == 2 ? 20:0), 700, "\n\nExit", GetColor(255, 255, 255));
}

void TitleScene::Update() {
	menu.Update();

	if (Input::Get().buttonstate[Button::A] == 1) {
		switch (menu.GetState())
		{
		case 0:
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