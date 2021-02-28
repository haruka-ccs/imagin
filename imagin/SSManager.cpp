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
	//PRTSCでssフォルダ下にスクショ保存、番号を進める()
	if (Input::Get().keystate[KEY_INPUT_SYSRQ] == 1) {
		SaveDrawScreenToPNG(0, 0, 1200, 900, filename);
		for (; PathFileExists(filename) == 1; num++) {
			sprintf_s(filename, "ss/ss%04d.png", num);
		}
	}
}

void SSManager::Init() {
	//ssフォルダ下を見てfilename.pngがあるか確認
	//あるならnumをなくなるまで進める
	for (num = 0; PathFileExists(filename) == 1; num++) {
		sprintf_s(filename, "ss/ss%04d.png", num);
	}
}
