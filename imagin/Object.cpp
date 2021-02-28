#include "Object.h"
#include"GameScene.h"

Object::Object() {
	Init();
}

void Object::Init() {
	pos = Vec2d(0, 0);
	verR = Vec2d(0, 0);
	verI = Vec2d(0, 0);
	accR = Vec2d(0, 0);
	accI = Vec2d(0, 0);
}

Object::Object(Vec2d pos) {
	Init();
	this->pos = pos;
}

void Object::SetPos(Vec2d pos){
	this->pos = pos;
}

void Object::SetVerR(Vec2d ver){
	this->verR = ver;
}

void Object::SetVerI(Vec2d ver) {
	this->verI = ver;
}

void Object::SetAccR(Vec2d acc) {
	this->accR = acc;
}

void Object::SetAccI(Vec2d acc) {
	this->accI = acc;
}

Vec2d Object::GetPos() {
	return this->pos;
}

Vec2d Object::GetVerR() {
	return this->verR;
}

Vec2d Object::GetVerI() {
	return this->verI;
}

Vec2d Object::GetAccR() {
	return this->accR;
}

Vec2d Object::GetAccI() {
	return this->accI;
}

long Object::GetCount() {
	return this->count;
}

double Object::GetRadius(){
	return r;
}

bool Object::isinArea() {
	if (pos.GetX() < GameSceneDefine::MARGIN ||
		(int)pos.GetX() > GameSceneDefine::PLAYAREA_WIDTH + GameSceneDefine::MARGIN ||
		pos.GetY() < GameSceneDefine::MARGIN ||
		(int)pos.GetY() > GameSceneDefine::PLAYAREA_HEIGHT + GameSceneDefine::MARGIN) {
		return false;
	}
	else {
		return true;
	}
}

void Object::UpdatePosR() {
	pos += verR;
}
void Object::UpdatePosI() {
	pos += verI;
}

void Object::UpdateVerR() {
	verR += accR;
}

void Object::UpdateVerI() {
	verI += accI;
}