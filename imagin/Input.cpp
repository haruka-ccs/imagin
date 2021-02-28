#include"Input.h"
#include"DxLib.h"
#include<math.h>



void Input::Update() {
	GetMousePoint(&mouse_X, &mouse_Y);

	//左クリック
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
		mouseStateL++;
	}
	else {
		mouseStateL = 0;
	}

	//右クリック
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {
		mouseStateR++;
	}
	else {
		mouseStateR = 0;
	}

	GetHitKeyStateAll(buf);
	for (int i = 0; i < 256; i++) {
		if (buf[i] == 1) {
			keystate[i]++;
		}
		else {
			keystate[i] = 0;
		}
	}

	if (padNum > 0) {
		for (int i = 0; i < 16; i++) {
			if ((padinput[0] & padtable[i]) != 0) {
				padstate[i]++;
			}
			else {
				padstate[i] = 0;
			}
		}
	}
}

Input::Input() {
	padNum = GetJoypadNum();
	
	for (int i = 0; i < padNum; i++) {
		padinput.push_back(GetJoypadInputState(i));
	}

	for (int i = 0; i < 256; i++) {
		buf[i] = 0;
		keystate[i] = 0;
	}

	for (int i = 0; i < 16; i++) {
		padtable[i] <<= i;		//PAD_INPUT_**の値を代入
	}
}

bool Input::ChangeRecept() {
	return canReceiveInput = (canReceiveInput == true ? false : true);
}

bool Input::GetRecept() {
	return canReceiveInput;
}