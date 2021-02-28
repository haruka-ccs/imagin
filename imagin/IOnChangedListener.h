#pragma once
#include "eScene.h"

class IOnSceneChangedListener
{
public:
	IOnSceneChangedListener() = default;
	virtual ~IOnSceneChangedListener() = default;
	virtual void onSceneChanged(const eScene scene, const bool stackClear, const bool fadeflag) = 0;
	virtual void ProceedScene() = 0;
};