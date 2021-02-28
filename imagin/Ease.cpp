#include "Ease.h"
#define _USE_MATH_DEFINES
#include <cmath>

EaseIO::EaseIO()
{
}


EaseI::EaseI()
{
}

EaseO::EaseO()
{
}

double EaseI::Quadratic(double t, int reqFrame, double start, double end)
{
	t /= reqFrame;
	return end*t*t + start;
}

double EaseO::Quadratic(double t, int reqFrame, double start, double end)
{
	t /= reqFrame;
	return -end*t*(t - 2) + start;
}

double EaseIO::Quadratic(double t, int reqFrame, double start, double end)
{
	if (t < reqFrame / 2) {
		return EaseI::Quadratic(t, reqFrame / 2, start, end / 2);
	}
	else {
		return EaseO::Quadratic(t - reqFrame / 2, reqFrame / 2, start + end / 2, end / 2);
	}
}


double EaseI::Cubic(double t, int reqFrame, double start, double end)
{
	t /= reqFrame;
	return end*t*t*t + start;
}

double EaseO::Cubic(double t, int reqFrame, double start, double end)
{
	t /= reqFrame;
	t--;
	return end*(t*t*t + 1) + start;
}

double EaseIO::Cubic(double t, int reqFrame, double start, double end)
{
	if (2 * t < reqFrame) {
		return EaseI::Cubic(t, reqFrame / 2, start, end / 2);
	}
	else {
		return EaseO::Cubic(t - reqFrame / 2, reqFrame / 2, end / 2, end);
	}
}

double EaseI::Quartic(double t, int reqFrame, double start, double end)
{
	t /= reqFrame;
	return end*t*t*t*t + start;
}

double EaseO::Quartic(double t, int reqFrame, double start, double end)
{
	t /= reqFrame;
	t--;
	return -end*(t*t*t*t - 1) + start;
}

double EaseIO::Quartic(double t, int reqFrame, double start, double end)
{
	if (2 * t < reqFrame) {
		return EaseI::Quartic(t, reqFrame / 2, start, end / 2);
	}
	else {
		return EaseO::Quartic(t - reqFrame / 2, reqFrame / 2, end / 2, end);
	}
}

double EaseI::Quintic(double t, int reqFrame, double start, double end)
{
	t /= reqFrame;
	return end*t*t*t*t*t + start;
}

double EaseO::Quintic(double t, int reqFrame, double start, double end)
{
	t /= reqFrame;
	t--;
	return end*(t*t*t*t*t + 1) + start;
}

double EaseIO::Quintic(double t, int reqFrame, double start, double end)
{
	if (2 * t < reqFrame) {
		return EaseI::Quintic(t, reqFrame / 2, start, end / 2);
	}
	else {
		return EaseO::Quintic(t - reqFrame / 2, reqFrame / 2, end / 2, end);
	}
}

double EaseI::Sinsoidal(double t, int reqFrame, double start, double end)
{
	t /= reqFrame;
	return -end*cos(t*M_PI_2) + start + end;
}

double EaseO::Sinsoidal(double t, int reqFrame, double start, double end)
{
	t /= reqFrame;
	return end*sin(t*M_PI_2) + start;
}

double EaseIO::Sinsoidal(double t, int reqFrame, double start, double end)
{
	if (2 * t < reqFrame) {
		return EaseI::Sinsoidal(t, reqFrame / 2, start, end / 2);
	}
	else {
		return EaseO::Sinsoidal(t - reqFrame / 2, reqFrame / 2, end / 2, end);
	}
}

double EaseI::Exponential(double t, int reqFrame, double start, double end)
{
	t /= reqFrame;
	return end*pow(2, 10 * (t - 1)) + start;
}

double EaseO::Exponential(double t, int reqFrame, double start, double end)
{
	t /= reqFrame;
	return end*(-pow(2, (-10 * t)) + 1) + start;
}

double EaseIO::Exponential(double t, int reqFrame, double start, double end)
{
	if (2 * t < reqFrame) {
		return EaseI::Exponential(t, reqFrame / 2, start, end / 2);
	}
	else {
		return EaseO::Exponential(t - reqFrame / 2, reqFrame / 2, end / 2, end);
	}
}

double EaseI::Circular(double t, int reqFrame, double start, double end)
{
	t /= reqFrame;
	return -end*(sqrt(1 - t*t) - 1) +start;
}

double EaseO::Circular(double t, int reqFrame, double start, double end)
{
	t /= reqFrame;
	t--;
	return end*sqrt(1 - t*t) +start;
}

double EaseIO::Circular(double t, int reqFrame, double start, double end)
{
	if (2 * t < reqFrame) {
		return EaseI::Circular(t, reqFrame / 2, start, end / 2);
	}
	else {
		return EaseO::Circular(t - reqFrame / 2, reqFrame / 2, end / 2, end);
	}
}