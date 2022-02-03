#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdlib.h>

using namespace std;



void inp(int** a, int n, int m) { //функція вводу масиву 
	srand(time(0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = rand() % 100;
}

void out(int** a, int n, int m)//функція вводу масиву
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[i][j] << setw(4) << "";
		cout << endl;
	}
	cout << endl;
}

void swap(int** a, int k, int l, int m, int n)//функція обміну стовпців
{
	for (int j = 0; j < m; j++)
	{
		int t = a[j][k];
		a[j][k] = a[j][l];
		a[j][l] = t;
	}
}
//функція пошуку мінімального та максимального елемента масиву

void min_max(int** a, int* k, int* l, int m, int n)
{
	int min = a[0][0];
	int max = a[0][0];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (min > a[i][j])
			{
				min = a[i][j];
				*k = j;
			}
			if (max < a[i][j])
			{
				max = a[i][j];
				*l = j;
			}
		}
}

int main()

{
	int n = 4;
	int m = 4;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[m];
	inp(a, n, m);
	int k, l;
	out(a, n, m);
	min_max(a, &k, &l, n, m);
	swap(a, k, l, n, m);
	cout << endl << endl;
	out(a, n, m);
	system("pause");
	return 0;

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;

}
