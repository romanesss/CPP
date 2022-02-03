#include <stdio.h>
#include <iostream>
using namespace std;
void binary_mask(unsigned x)
{
	for (unsigned mask = 1 << (sizeof(int) * 8 - 1); mask; mask >>= 1)
		(x & mask ? cout << "1" : cout << "0");
	cout << "\n";
}

int bit(unsigned int x, int n, int p)
{
	unsigned y = (((1 << n) - 1) << p) | x;
	return y;
}

int main()
{
	unsigned x = 0;
	int p = 0;
	int n = 0;
	cout << "Enter an x: ";
	cin >> x;
	cout << "Enter an n: ";
	cin >> n;
	cout << "Enter an p: ";
	cin >> p;
	binary_mask(x);
	unsigned y = bit(x, p, n);
	binary_mask(y);
	cout << y << endl;
	system("pause");
}
