#include "ConfigScene.h"
#include "Input.h"
#include"DxLib.h"

ConfigScene::ConfigScene(IOnSceneChangedListener* _impl) :SceneBase(_impl) {

}

void ConfigScene::Draw() {
	DrawString(0, 0, "Config", GetColor(255, 255, 255));

	for (int i = 0; i < 16; ++i) {
		//DrawFormatString(50, 30 * i, GetColor(255, 255, 255), "%d:%d:%d", i, Input::Get().padstate[i], Input::Get().buttonstate[i]);
	}

	for (int i = 0; i < keyconfig.GetNum(); ++i) {
		int color = GetColor(255, 255, 255);

		if (i == keyconfig.GetState()) {
			if (inputwait == keyconfig.GetState()) {
				color = GetColor(255, 0, 0);
			}
		}
		if (i != keyconfig.GetNum() - 1) {
			DrawFormatString(100, 100 + 30 * i, color, "button %s  : %02d", Button::ToStr(i).c_str(), Input::Get().GetPadCorr(i));
		}
		else {
			DrawString(100, 100 + 30 * i, "exit", color);
		}
	}

	DrawString(80, 100 + 30 * keyconfig.GetState(), ">", GetColor(255, 255, 255));
}

void ConfigScene::Update() {

	if (Input::Get().buttonstate[Button::A] == 1 && change == false) {
		if (keyconfig.GetState() == keyconfig.GetNum() - 1) {
			_implSceneChanged->BackScene();
		}
		else {
			inputwait = keyconfig.GetState();
		}
		++Input::Get().buttonstate[Button::A];
	}
	if (inputwait != -1) {
		if (Input::Get().NoPadInput() == true) {
			change = true;
		}
		if (change==true&&Input::Get().SetPadCorr(inputwait)) {
			inputwait = -1;
			change = false;
		}
	}
	else {
		keyconfig.Update();
	}
}