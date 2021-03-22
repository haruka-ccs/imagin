#pragma once

#include<vector>
#include<string>

//PAD_INPUT_**�ɂ����ď����l�̂Ƃ��ォ�牽�Ԗڂ�
#define PAD_DOWN		0		//PAD_INPUT_DOWN
#define PAD_LEFT		1		//PAD_INPUT_LEFT
#define PAD_RIGHT		2		//PAD_INPUT_RIGHT
#define PAD_UP			3		//PAD_INPUT_UP
#define PAD_SHOT		4		//PAD_INPUT_1
#define PAD_BOMB		5		//PAD_INPUT_2
#define PAD_SLOW		9		//PAD_INPUT_6
#define PAD_PAUSE		11		//PAD_INPUT_8

namespace Button{
	const int DOWN	= 0;
	const int LEFT	= 1;
	const int RIGHT = 2;
	const int UP	= 3;
	const int A		= 4;
	const int B		= 5;
	const int X		= 6;
	const int Y		= 7;
	const int L		= 8;
	const int R		= 9;

	std::string ToStr(int button);
}


//DualShock4�
namespace Pad {
	const int DOWN	= 0;
	const int LEFT	= 1;
	const int RIGHT = 2;
	const int UP	= 3;
	const int Y		= 4;
	const int B		= 5;
	const int A		= 6;
	const int X		= 7;
	const int L		= 8;
	const int R		= 9;
	const int LT	= 10;
	const int RT	= 11;
	const int SELECT = 12;
	const int START = 13;
	const int L3	= 14;
	const int R3	= 15;
}

class Input {
private:
	Input();
	Input(const Input& r) = delete;
	Input& operator=(const Input& r) = delete;

	static const int KEY_NUM = 256;
	static const int BUTTON_NUM = 16;
	static const int PAD_NUM = 16;


	//push == 1�Arelease == 0
	char buf[KEY_NUM];

	//���͎�t
	bool canReceiveInput = true;
	
	int padinput;

	int padtable[24] = { 1 };
	int padNum;

	int mouseX = 0, mouseY = 0;

	int mouseStateL = 0, mouseStateR = 0;

	//Button::XX �� KEY_INPUT_XX / PAD_INPUT_XX �ɕϊ�
	//�L�[�R���͂����ύX����
	//-1�͖����蓖��
	int keycorr[BUTTON_NUM];
	int padcorr[BUTTON_NUM];

public:
	int padstate[24];

	static Input& Get() {
		static Input inst;
		return inst;
	}

	int keystate[KEY_NUM];

	//Button::XX�ŌĂяo��
	int buttonstate[BUTTON_NUM] = { 0 };

	void Update();

	//inputRecept�𔽓]���A���̏�Ԃ�Ԃ�
	bool ChangeRecept();

	bool GetRecept();

	int GetKeyState(int key);
	
	int GetKeyCorr(int key);
	int GetPadCorr(int pad);

	bool SetPadCorr(int button);

	bool NoPadInput();
};