#include "Fade.h"
#include "DxLib.h"

Fade::Fade(IOnSceneChangedListener* _impl) :SceneBase(_impl) {
	this->Init();
}

void Fade::Draw(){
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, fadecount);
	DrawBox(0, 0, 1200, 900, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawFormatString(100, 100, GetColor(0, 0, 0), "fadecount:%d",fadecount);
}

void Fade::Update(){
	count++;
	//if (count % 2 == 1) {
	    if (fadereverse == false) {
			if (fadecount < 255) {
				fadecount += 2;
			}
			else {
				hiddencount++;
			}
		}
		else {
			fadecount -= 2;
		}
		if (hiddencount > 5) {
			fadereverse = true;
			_implSceneChanged->ProceedScene();
		}
		if (fadecount <= 0) {
			finish = true;
		}
	//}
}

void Fade::Init(){
	fadecount = 0;
	count = 0;
	hiddencount = 0;
	fadereverse = false;
	finish = false;
}

bool Fade::CheckFinish()
{
	return finish;
}
