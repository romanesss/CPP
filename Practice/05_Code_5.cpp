#include <conio.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int destination = 0;
	int order = 0;

start_point:
	cout << "1-North\n2-South\n3-East\n4-West\n";
	cout << "Input destination: ";
	cin >> destination;

	cout << "\n5-Front\n6-Back\n7-Left\n8-Right\n";
	cout << "Input order: ";
	cin >> order;

	if (destination <= 0 || destination > 4 || order <= 4 || order > 8)
	{
		cout << "Input data is not correct.\n";
		goto start_point;
	}



	switch (destination + order * order)
	{

	case 26: case 38: case 52: case 68:
		cout << "New Destination - North"; break;  //N-F

	case 27: case 37: case 53: case 67:
		cout << "New Destination - South"; break; //S-F

	case 28: case 40: case 51: case 65:
		cout << "New Destination - East"; break;//E-F

	case 29: case 39: case 50: case 66:
		cout << "New Destination - West"; break;//W-F

	}
	_getch();
	return 0;

}