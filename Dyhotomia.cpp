#include "Dyhotomia.h"

#include <cmath>

Dyhotomia::Dyhotomia()
{
	a = 0;
	b = 0;
	eps = 0;
}

void Dyhotomia::setVolumes(double vol_a, double vol_b)
{
	a = vol_a;
	b = vol_b;
}

void Dyhotomia::setTolerance(double vol_eps)
{
	eps = vol_eps;
}

double Dyhotomia::Solve()
{
	if (func(a) * func(b) > 0)
	{
		return -funcMin();
	}

	do
	{
		double c = (a + b) / 2;
		if (func(a) * func(c) < 0)
		{
			b = c;
		}
		else
		{
			a = c;
		}
	} while (abs(b - a) <= eps);

	return (a + b) / 2.0;
}

double Dyhotomia::func(double arg)
{
	return (3*sin(sqrt(arg)) + 0.35 * arg - 3.8);
}

double Dyhotomia::funcMin()
{
	double r = func(a);

	for (double c = a; c <= b; c += eps)
	{
		if (func(c) < r)
		{
			r = func(c);
		}
	}

	return r;
}

double Dyhotomia::funcMax()
{
	double r = func(a);

	for (double c = a; c <= b; c += eps)
	{
		if (func(c) > r)
		{
			r = func(c);
		}
	}

	return r;
}

double Dyhotomia::getA()
{
	return a;
}

double Dyhotomia::getB()
{
	return b;
}