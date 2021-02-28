#pragma once
#include"IOnChangedListener.h"
#include"Param.h"

class SceneBase {
protected:
	IOnSceneChangedListener* _implSceneChanged;

	long count;

	Param _param;
public:
	SceneBase(IOnSceneChangedListener* impl) :_implSceneChanged(impl) {
		count = 0;
	}

	SceneBase(IOnSceneChangedListener* impl, Param param): _implSceneChanged(impl),_param(param) {
		count = 0;
	}

	virtual void Update() = 0;

	virtual void Draw() = 0;

	//bool hard = false;
};