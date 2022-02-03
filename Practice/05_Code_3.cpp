#include <math.h>
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	float  a = 3.1, b = 6.2, c = 1.03, d = 2.7;
	double y = 2 * fabs(asin(-sqrt(c / d))) + cos(pow(a, b));
	cout << "Result= " << y;
	_getch();
	return 0;
}
