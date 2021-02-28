#pragma once
#include "SceneBase.h"

class TitleScene :public SceneBase{
private:

public:
	TitleScene(IOnSceneChangedListener* _impl);
	
	void Draw();

	void Update();
};