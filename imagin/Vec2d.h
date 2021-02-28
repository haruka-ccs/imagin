#pragma once
#include<cmath>

class Vec2d {
private:
	double x = 0;
	double y = 0;
public:
	Vec2d() {};
	Vec2d(double x, double y) :x(x), y(y) {};
	double GetX() { return x; };
	double GetY() { return y; };

	void SetX(double x) { this->x = x; };
	void SetY(double y) { this->y = y; };

	void AddX(double a) { this->x += a; };
	void AddY(double a) { this->y += a; };

	void operator+=(Vec2d v) {
		this->x += v.GetX();
		this->y += v.GetY();
	}

	Vec2d operator+(Vec2d v) {
		return Vec2d(this->x + v.x, this->y + v.y);
	}
	Vec2d operator-(Vec2d v) {
		return Vec2d(this->x - v.x, this->y - v.y);
	}

	double Mag() {
		return sqrt(pow(x, 2) + pow(y, 2));
	}
};