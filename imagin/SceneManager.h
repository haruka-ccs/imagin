#pragma once
#include"SceneBase.h"
#include"eScene.h"
#include<stack>
#include<memory>
#include"Fade.h"

class SceneManager final :public IOnSceneChangedListener {
private:
	std::stack<std::shared_ptr<SceneBase>> sceneStack;

	eScene t_next = eScene::Title;
	bool t_clear = false;
	bool fadeflag;

public:
	SceneManager();
	
	Fade fade = Fade(this);

	void onSceneChanged(eScene next, const bool clear, const bool fadeflag);

	void BackScene();

	void ProceedScene();

	void Update();

	void Draw();
};