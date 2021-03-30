#pragma once

class Choice {
private:
	int num;
	int state = 0;

public:
	Choice(int num) :num(num) {};
	int GetState();
	int GetNum();
	void SetState(int state);
	void Update(int dir);
	void Update();
};