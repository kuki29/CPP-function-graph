#pragma once

ref class Dyhotomia
{
public:
	Dyhotomia();

	void setVolumes(double vol_a, double vol_b);
	void setTolerance(double vol_eps);
	double Solve();
	double funcMin();
	double funcMax();
	double getA();
	double getB();
	double func(double arg);

private:
	double a;
	double b;
	double eps;
};

