#include"Choice.h"
#include"Input.h"

int Choice::GetNum(){
	return num;
}

int Choice::GetState() {
	return state;
}

void Choice::Update(int dir) {
	state = (state + num + dir) % num;
}

void Choice::Update() {
	if (Input::Get().buttonstate[Button::UP] % 15 == 1) {
		Update(-1);
	}
	if (Input::Get().buttonstate[Button::DOWN] % 15 == 1) {
		Update(1);
	}
}