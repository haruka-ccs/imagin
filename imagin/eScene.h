#pragma once
using namespace std;

enum eScene {
	Title,
	Game,
	GameOver,
	Clear
};

//boost::bimapで実装しなおす
//char* ToString(eScene scene);