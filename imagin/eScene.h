#pragma once
using namespace std;

enum class eScene {
	Title,
	Game,
	GameOver,
	Config,
	Clear
};

//boost::bimapで実装しなおす
//char* ToString(eScene scene);