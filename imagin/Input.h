#pragma once

#include<vector>

//PAD_INPUT_**�ɂ����ď����l�̂Ƃ��ォ�牽�Ԗڂ�
#define PAD_DOWN		0		//PAD_INPUT_DOWN
#define PAD_LEFT		1		//PAD_INPUT_LEFT
#define PAD_RIGHT		2		//PAD_INPUT_RIGHT
#define PAD_UP			3		//PAD_INPUT_UP
#define PAD_SHOT		4		//PAD_INPUT_1
#define PAD_BOMB		5		//PAD_INPUT_2
#define PAD_SLOW		9		//PAD_INPUT_6
#define PAD_PAUSE		11		//PAD_INPUT_8

namespace input{
	const int MAX_PAD_NUM = 4;

};

class Input {
private:
	Input();
	Input(const Input& r) = delete;
	Input& operator=(const Input& r) = delete;

	char buf[256];

	//���͎�t
	bool canReceiveInput = true;

	std::vector<int> padinput;

	int padtable[24] = { 1 };

	int padNum;
public:
	int padstate[24];

	static Input& Get() {
		static Input inst;
		return inst;
	}

	int keystate[256];

	void Update();

	//inputRecept�𔽓]���A���̏�Ԃ�Ԃ�
	bool ChangeRecept();

	bool GetRecept();
	
	int mouse_X = 0, mouse_Y = 0;

	int mouseStateL = 0, mouseStateR = 0;
};