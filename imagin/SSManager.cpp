#include "SSManager.h"
#include"Input.h"
#include"DxLib.h"

#include <shlwapi.h>
#pragma comment( lib , "shlwapi.lib" )

SSManager::SSManager()
{
	Init();
}


SSManager::~SSManager()
{
}

void SSManager::Update() {
	//PRTSC��ss�t�H���_���ɃX�N�V���ۑ��A�ԍ���i�߂�()
	if (Input::Get().keystate[KEY_INPUT_SYSRQ] == 1) {
		SaveDrawScreenToPNG(0, 0, 1200, 900, filename);
		for (; PathFileExists(filename) == 1; num++) {
			sprintf_s(filename, "ss/ss%04d.png", num);
		}
	}
}

void SSManager::Init() {
	//ss�t�H���_��������filename.png�����邩�m�F
	//����Ȃ�num���Ȃ��Ȃ�܂Ői�߂�
	for (num = 0; PathFileExists(filename) == 1; num++) {
		sprintf_s(filename, "ss/ss%04d.png", num);
	}
}
