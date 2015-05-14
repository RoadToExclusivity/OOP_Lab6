#include "stdafx.h"
#include "EquationRoot.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	double a, b, c, d, e;
	cout << "Input coefs: ";
	while (cin >> a >> b >> c >> d >> e)
	{
		try
		{
			EquationRoot4 res = Solve(a, b, c, d, e);
			cout << res.numRoots << " roots:" << endl;
			for (int i = 0; i < res.numRoots; ++i)
			{
				cout << res.roots[i] << endl;
			}
		}
		catch (exception e)
		{
			cout << "Error: " << e.what() << endl;
		}

		cout << "Input coefs: ";
	}
	return 0;
}

