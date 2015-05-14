#include "stdafx.h"
#include "../task1/EquationRoot.h"

using namespace std;

const double EPS = 1e-6;

BOOST_AUTO_TEST_CASE(NoRealRoots)
{
	EquationRoot4 res;
	{
		try
		{
			res = Solve(0, 1, 15, 1, 5);
			BOOST_CHECK(false);
		}
		catch (invalid_argument)
		{
			BOOST_CHECK(true);
		}
	}
	{
		try
		{
			res = Solve(15, 1, 15, 1, 5);
			BOOST_CHECK(false);
		}
		catch (domain_error)
		{
			BOOST_CHECK(true);
		}
	}
}

BOOST_AUTO_TEST_CASE(HaveRealRoots)
{
	EquationRoot4 res;
	{
		try
		{
			res = Solve(1, 0, 0, 0, -16);
			BOOST_CHECK_EQUAL(res.numRoots, 2);
			BOOST_CHECK_CLOSE(res.roots[0], -2, EPS);
			BOOST_CHECK_CLOSE(res.roots[1], 2, EPS);
			BOOST_CHECK(true);
		}
		catch (exception)
		{
			BOOST_CHECK(false);
		}
	}

	{
		try
		{
			res = Solve(1, 2, -3, 0, 5);
			BOOST_CHECK_EQUAL(res.numRoots, 2);
			BOOST_CHECK_CLOSE(res.roots[0], -2.83829802, EPS);
			BOOST_CHECK_CLOSE(res.roots[1], -1.120053711, EPS);
			BOOST_CHECK(true);
		}
		catch (exception)
		{
			BOOST_CHECK(false);
		}
	}

	{
		try
		{
			res = Solve(21, -44, 7, 15, 2);
			BOOST_CHECK_EQUAL(res.numRoots, 4);
			BOOST_CHECK_CLOSE(res.roots[0], -0.36751669, EPS);
			BOOST_CHECK_CLOSE(res.roots[1], -0.157062608, EPS);
			BOOST_CHECK_CLOSE(res.roots[2], 1.05310406, EPS);
			BOOST_CHECK_CLOSE(res.roots[3], 1.5667133277, EPS);
			BOOST_CHECK(true);
		}
		catch (exception)
		{
			BOOST_CHECK(false);
		}
	}

	{
		try
		{
			res = Solve(5, 5, 5, 5, 0);
			BOOST_CHECK_EQUAL(res.numRoots, 2);
			BOOST_CHECK_CLOSE(res.roots[0], -1.00000004, EPS);
			BOOST_CHECK_CLOSE(res.roots[1], 0, EPS);
			BOOST_CHECK(true);
		}
		catch (exception)
		{
			BOOST_CHECK(false);
		}
	}
}