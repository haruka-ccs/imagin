#pragma once
#include"IOnChangedListener.h"
#include"eScene.h"
#include"SceneBase.h"

class Fade :public SceneBase{
private:	
	int type;

	int fadecount;
	int hiddencount;
	int count;

	bool fadereverse;

	bool finish;
public:
	Fade(IOnSceneChangedListener* _impl);

	void Draw();

	void Update();

	void Init();

	bool CheckFinish();

	//void SetFadeOptions();
};