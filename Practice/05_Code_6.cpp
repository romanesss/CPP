#include<iostream>
using namespace std;
int main()
{
	cout << "Input number ";
	int x = 0;
	cin >> x;
	for (int k = 2; k <= x; k++)
	{
		int n = k;
		while (n % 2 == 0)
		{
			n = n / 2;
		}
		while (n % 3 == 0)
		{
			n = n / 3;
		}
		while (n % 5 == 0)
		{
			n = n / 5;
		}
		if (n == 1)
			cout << k << "; ";
	}
	cout << endl;
	return 0;
}
