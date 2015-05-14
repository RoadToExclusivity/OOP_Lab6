#include "stdafx.h"
#include "EquationRoot.h"

using namespace std;

const double EPS = 1e-10;

bool IsZero(double a)
{
	return (fabs(a) <= EPS);
}

bool IsEqual(double a, double b)
{
	return IsZero(a - b);
}

int Sign(double a)
{
	if (IsZero(a))
	{
		return 0;
	}

	if (a > 0)
	{
		return 1;
	}

	return -1;
}

double F3(double x, double a, double b, double c, double d)
{
	return 1.0 * (a * x * x * x + b * x * x + c * x + d);
}

double F4(double x, double a, double b, double c, double d, double e)
{
	return F3(x, a, b, c, d) * x + e;
}

double ChoosingFunc(double x, double a, double b, double c, double d, double e, bool isFor4)
{
	if (isFor4)
	{
		return F4(x, a, b, c, d, e);
	}
	
	return F3(x, a, b, c, d);
}

double BinSearch(double l, double r, double a, double b, double c, double d, double e, bool isFor4)
{
	if (IsZero(ChoosingFunc(l, a, b, c, d, e, isFor4)))
	{
		return l;
	}

	if (IsZero(ChoosingFunc(r, a, b, c, d, e, isFor4)))
	{
		return r;
	}

	while (!IsEqual(l, r))
	{
		double m = (l + r) / 2.0;
		double newVal = ChoosingFunc(m, a, b, c, d, e, isFor4),
			lVal = ChoosingFunc(l, a, b, c, d, e, isFor4), rVal = ChoosingFunc(r, a, b, c, d, e, isFor4);

		if (IsZero(newVal))
		{
			return m;
		}

		if ((newVal > 0 && lVal > rVal) || (newVal < 0 && lVal < rVal))
		{
			l = m;
		}
		else
		{
			r = m;
		}
	}

	return l;
}

EquationRoot4 Solve(double a, double b, double c, double d, double e)
{
	if (a == 0)
	{
		throw invalid_argument("a == 0");
	}

	double discriminant = 36.0 * b * b - 96.0 * a * c;
	double sqrt4_DBL_MAX = sqrt(sqrt(DBL_MAX));
	if (discriminant < 0 && !IsZero(discriminant))
	{
		throw domain_error("No real roots");
	}

	vector<double> squareEqRes;
	squareEqRes.push_back(-sqrt4_DBL_MAX);
	if (IsZero(discriminant))
	{
		double x = b / (4.0 * a);
		squareEqRes.push_back(x);
	}
	else
	{
		double sqrtD = sqrt(discriminant);
		double x1 = (-6.0 * b - sqrtD) / (24 * a), x2 = (-6.0 * b + sqrtD) / (24 * a);
		squareEqRes.push_back(x1);
		squareEqRes.push_back(x2);
	}
	squareEqRes.push_back(sqrt4_DBL_MAX);

	double a2 = 4 * a, b2 = 3 * b, c2 = 2 * c;
	vector<double> res3;
	
	vector<int> sign3;
	if (a > 0)
	{
		sign3.push_back(-1);
	}
	else
	{
		sign3.push_back(1);
	}
	for (size_t i = 1; i < squareEqRes.size() - 1; ++i)
	{
		sign3.push_back(Sign(F3(squareEqRes[i], a2, b2, c2, d)));
	}
	if (a > 0)
	{
		sign3.push_back(1);
	}
	else
	{
		sign3.push_back(-1);
	}

	res3.push_back(-sqrt4_DBL_MAX);
	for (size_t i = 1; i < squareEqRes.size(); ++i)
	{
		if (sign3[i - 1] != sign3[i])
		{
			double res = BinSearch(squareEqRes[i - 1], squareEqRes[i], a2, b2, c2, d, 0, false);
			res3.push_back(res);
		}
	}
	res3.push_back(sqrt4_DBL_MAX);

	if (res3.size() == 2)
	{
		throw domain_error("No real roots");
	}

	vector<double> res;
	vector<int> sign4;
	if (a > 0)
	{
		sign4.push_back(1);
	}
	else
	{
		sign4.push_back(-1);
	}
	for (size_t i = 1; i < res3.size() - 1; ++i)
	{
		sign4.push_back(Sign(F4(res3[i], a, b, c, d, e)));
	}
	if (a > 0)
	{
		sign4.push_back(1);
	}
	else
	{
		sign4.push_back(-1);
	}

	for (size_t i = 1; i < res3.size(); ++i)
	{
		if (sign4[i - 1] != sign4[i])
		{
			double resFor4 = BinSearch(res3[i - 1], res3[i], a, b, c, d, e, true);
			res.push_back(resFor4);
		}
	}
	
	if (res.size() == 0)
	{
		throw domain_error("No real roots");
	}

	EquationRoot4 result;
	result.numRoots = res.size();
	for (size_t i = 0; i < res.size(); ++i)
	{
		result.roots[i] = res[i];
	}

	return result;
}