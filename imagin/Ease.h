#pragma once
class EaseIO
{
public:
	EaseIO();

	//2次
	static double Quadratic(double t, int reqFrame, double start = 0, double end = 1);

	//3次
	static double Cubic(double t, int reqFrame, double start = 0, double end = 1);
	
	//4次
	static double Quartic(double t, int reqFrame, double start = 0, double end = 1);
	
	//5次
	static double Quintic(double t, int reqFrame, double start = 0, double end = 1);

	//sin
	static double Sinsoidal(double t, int reqFrame, double start = 0, double end = 1);
	
	//exp
	static double Exponential(double t, int reqFrame, double start = 0, double end = 1);
	
	//円
	static double Circular(double t, int reqFrame, double start = 0, double end = 1);

};

class EaseI
{
public:
	EaseI();

	//2次
	static double Quadratic(double t, int reqFrame, double start = 0, double end = 1);

	//3次
	static double Cubic(double t, int reqFrame, double start = 0, double end = 1);

	//4次
	static double Quartic(double t, int reqFrame, double start = 0, double end = 1);

	//5次
	static double Quintic(double t, int reqFrame, double start = 0, double end = 1);

	//sin
	static double Sinsoidal(double t, int reqFrame, double start = 0, double end = 1);

	//exp
	static double Exponential(double t, int reqFrame, double start = 0, double end = 1);

	//円
	static double Circular(double t, int reqFrame, double start = 0, double end = 1);

};

class EaseO
{
public:
	EaseO();

	//2次
	static double Quadratic(double t, int reqFrame, double start = 0, double end = 1);

	//3次
	static double Cubic(double t, int reqFrame, double start = 0, double end = 1);

	//4次
	static double Quartic(double t, int reqFrame, double start = 0, double end = 1);

	//5次
	static double Quintic(double t, int reqFrame, double start = 0, double end = 1);

	//sin
	static double Sinsoidal(double t, int reqFrame, double start = 0, double end = 1);

	//exp
	static double Exponential(double t, int reqFrame, double start = 0, double end = 1);

	//円
	static double Circular(double t, int reqFrame, double start = 0, double end = 1);

};
