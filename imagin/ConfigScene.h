#pragma once
#include "SceneBase.h"
#include"Choice.h"

class ConfigScene :public SceneBase {
private:
	Choice keyconfig = Choice(11);

	int inputwait = -1;
	bool change = false;
public:
	ConfigScene(IOnSceneChangedListener* _impl);

	void Draw();

	void Update();

	
};