#pragma once
#include "SceneBase.h"
#include "Player.h"
#include "BulletManager.h"

#include"StageBase.h"

namespace GameSceneDefine{
	const int MARGIN = 30;
	const int PLAYAREA_WIDTH = 650;
	const int PLAYAREA_HEIGHT = 900 - 60;
}

class GameScene :public SceneBase{
private:
	Player player;
	StageBase* stage;

	BulletManager *_bm = new BulletManager();

	static bool isReality;

	int hitcount = 0;
public:
	GameScene(IOnSceneChangedListener* _impl);

	void Draw();

	void Update();

	//“–‚½‚è”»’è(‰¼)
	void Collision();

	void SetReality(bool flag);
	void ChangeReality();
	static bool GetReality();
};