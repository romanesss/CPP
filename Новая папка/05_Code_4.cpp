#include <math.h>
#include <conio.h>
#include <iostream>
using namespace std;
int main()
{
	float x = 0, y = 0, R = 0;
	cout << "Input x ="; cin >> x;
	cout << "input y = "; cin >> y;
	cout << "input radius R = "; cin >> R;
	if (pow(x, 2) + pow(y, 2) > pow(R, 2))
		cout << "Poin is outside the circle ";
	else
	{
		cout << "The point is inside the circle, ";
		if ((y - x) > R)
			cout << " above the line and does not fall into the area ";
		else
		{
			cout << " below the line and falls into the area ";
		}
	}
	_getch();
	return 0;
}
