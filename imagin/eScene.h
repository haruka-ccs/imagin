#pragma once
using namespace std;

enum class eScene {
	Title,
	Game,
	GameOver,
	Config,
	Clear
};

//boost::bimap�Ŏ������Ȃ���
//char* ToString(eScene scene);