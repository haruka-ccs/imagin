#include"Input.h"
#include"DxLib.h"
#include<math.h>



void Input::Update() {
	GetMousePoint(&mouseX, &mouseY);

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
	for (int i = 0; i < KEY_NUM; i++) {
		if (buf[i] == 1) {
			keystate[i]++;
		}
		else {
			keystate[i] = 0;
		}
	}

	padinput = GetJoypadInputState(DX_INPUT_PAD1);
	if (padNum > 0) {
		for (int i = 0; i < 16; i++) {
			if ((padinput & padtable[i]) != 0) {
				padstate[i]++;
			}
			else {
				padstate[i] = 0;
			}
		}
	}

	for (int i = 0; i < BUTTON_NUM; ++i) {
		if ((keycorr[i] != -1 && keystate[keycorr[i]] > 0) ||
			(padcorr[i] != -1 && padstate[padcorr[i]] > 0) == 1) {
			++buttonstate[i];
		}
		else {
			buttonstate[i] = 0;
		}
	}

}

Input::Input() {
	padNum = GetJoypadNum();

	for (int i = 0; i < 256; i++) {
		buf[i] = 0;
		keystate[i] = 0;
	}

	for (int i = 0; i < 16; i++) {
		padtable[i] = (1<<i);		//PAD_INPUT_**の値を代入
	}

	for (int i = 0; i < BUTTON_NUM; ++i) {
		keycorr[i] = -1;
		padcorr[i] = -1;
	}

	keycorr[Button::DOWN]	= KEY_INPUT_DOWN;
	keycorr[Button::LEFT]	= KEY_INPUT_LEFT;
	keycorr[Button::RIGHT]	= KEY_INPUT_RIGHT;
	keycorr[Button::UP]		= KEY_INPUT_UP;
	keycorr[Button::A]		= KEY_INPUT_Z;
	keycorr[Button::B]		= KEY_INPUT_X;
	keycorr[Button::X]		= KEY_INPUT_A;
	keycorr[Button::R]		= KEY_INPUT_LSHIFT;

	padcorr[Button::DOWN] = Pad::DOWN;
	padcorr[Button::LEFT] = Pad::LEFT;
	padcorr[Button::RIGHT] = Pad::RIGHT;
	padcorr[Button::UP] = Pad::UP;
	padcorr[Button::A] = Pad::Y;
	padcorr[Button::B] = Pad::B;
	padcorr[Button::X] = Pad::X;
	padcorr[Button::R] = Pad::R;
}

bool Input::ChangeRecept() {
	return canReceiveInput = (canReceiveInput == true ? false : true);
}

bool Input::GetRecept() {
	return canReceiveInput;
}

int Input::GetKeyState(int key) {
	if (key < 0 || key > KEY_NUM) {
		return 0;
	}
	return keystate[key];
}

int Input::GetKeyCorr(int key) {
	return keycorr[key];
}


int Input::GetPadCorr(int pad) {
	return padcorr[pad];
}

bool Input::SetPadCorr(int button) {
	int dest = -1;

	for (int i = 0; i < PAD_NUM; ++i) {
		if (padstate[i] == 1) {
			dest = i;
			break;
		}
	}
	if (dest == -1) {
		return false;
	}

	//被りがないか調べる
	int temp = -1;
	for (int i = 0; i < BUTTON_NUM; ++i) {
		if (padcorr[i] == dest) {
			temp = i;
		}
	}

	if (temp != -1) {
		padcorr[temp] = padcorr[button];
	}
	padcorr[button] = dest;

	return true;
}

bool Input::NoPadInput() {
	for (int i = 0; i < 16; ++i) {
		if (padstate[i] > 0) {
			return false;
		}
	}
	return true;
}

std::string Button::ToStr(int button) {

	std::string res;
	switch (button)
	{
	case Button::DOWN:
		res = "DOWN";
		break;
	case Button::LEFT:
		res = "LEFT";
		break;
	case Button::RIGHT:
		res = "RIGHT";
		break;
	case Button::UP:
		res = "UP";
		break;
	case Button::A:
		res = "A";
		break;
	case Button::B:
		res = "B";
		break;
	case Button::X:
		res = "X";
		break;
	case Button::Y:
		res = "Y";
		break;
	case Button::L:
		res = "L";
		break;
	case Button::R:
		res = "R";
		break;
	default:
		break;
	}
	return res;
}
