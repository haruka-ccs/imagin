#pragma once
#include "SceneBase.h"
#include "Choice.h"

class TitleScene :public SceneBase{
private:
	Choice menu = Choice(3);
public:
	TitleScene(IOnSceneChangedListener* _impl);
	
	void Draw();

	void Update();
};