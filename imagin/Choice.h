#pragma once

class Choice {
private:
	int num;
	int state = 0;

public:
	Choice(int num) :num(num) {};
	int GetState();
	int GetNum();
	void Update(int dir);
	void Update();
};