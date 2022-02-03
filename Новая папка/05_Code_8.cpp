#include <iostream>
using namespace std;

int Binom(int m, int n)
{
	if (m == 0 || m == n)
		return 1;
	else
		return Binom(m, n - 1) + Binom(m - 1, n - 1);

}
int main()
{
	int m = 0;
	int n = 0;
	cout << "vvedit m --"; cin >> m;
	cout << "vvedit n --"; cin >> n;
	if (m < 0 || n < 0 || n < m)
	{
		cout << "error\n";
		return 0;
	}

	cout << Binom(m, n) << endl;
	return 0;
}
