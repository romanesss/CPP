#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <string>

using namespace std;

double getRec(double, int); // ������� ����������� �������
long double getValue(double); // ������� �������� ��������
long double getSuma(double, double, double, int&); // ���������� ������� ��� ������� ���� ����
long double getSeriesSum(double, double, int&); // ������� ��������� ����
void calculate(double, double, double, double); // ������� ���� � �������� ��������
void readConsole(double&, double&, double&, double&); // ���� � ������
void readFile(double&, double&, double&, double&); // ���� � �����
bool validation(double, double, double, double); // �������� �������� ������


int main()
{

	double begin = 0, end = 0, delta = 0, eps = 2; // ���� ��� ��������� ������� ������
	int mode = 0;	// ����� ����������
	cout << " Read values from console (1) or Read values from file (2): ";
	cin >> mode;
	system("cls");
	if (mode != 1 && mode != 2)
	{
		cout << "Invalid mode!" << endl; system("pause"); exit(0);
	}
	if (mode == 1)
	{
		readConsole(begin, end, delta, eps);
	}
	if (mode == 2)
	{
		readFile(begin, end, delta, eps);
	}
	if (validation(begin, end, delta, eps)) // ���� ���� �����
		calculate(begin, end, delta, eps);	// ��������� ������� 
	else // ���� ���� �� �����
		cout << "Invalid values!" << endl;	// �������� �������
	system("pause");	// �����, ��� ������� �� �����������
	return 0;
}

// ������� ������� ����� ������ ����, ������ � �� ����� �������� �����
double getRec(double x, int n)
{
	return x / n; // ������� ������ ��� ����� ����
}

// ������� ������� ����� �������� ���� �������, ������ �
long double getValue(double x)
{
	return exp(x); // ���� �������
}

// ���������� ������� ��������� ���� ����
long double getSuma(double x, double el, double eps, int& n) {

	if (fabs(el) > eps) // ����� ������ � ������
	{
		n++;
		return el + getSuma(x, el * getRec(x, n), eps, n);
	}

	return 0; // ����� � ������
}

// ������� ������� ���� �����, ������ �, ��������� �������, ��������� �� �������� �������� �����
long double getSeriesSum(double x, double eps, int& n)
{



	n = 0;
	long double current = 1;
	long double prev = 0;
	long double sum = 0;

	sum = getSuma(x, current, eps, n);


	return sum; // ��������� ���������
}

// ������� ���� ���� ��� ���� �� ������� �� xBegin �� xEnd � ������ - delta �� �������� - eps
void calculate(double xBegin, double xEnd, double delta, double eps)
{

	//	ofstream file("out.txt"); // ��������� ���� ��� ���������� ����������
	FILE* file;

	fopen_s(&file, "out.txt", "w");
	double x = xBegin;
	system("cls");

	cout << setw(7) << "X" << setw(15) << "SERIES" << setw(15) << "EXACT" << setw(20) << "ERROR" << setw(11) << "STEPS" << endl; // �������� ����� ������� � �������


	while (x <= xEnd)
	{
		int n = 0;
		double series = 0;
		double func = 0;


		series = getSeriesSum(x, eps, n);	// ������ �������� �� ��������� �����
		func = getValue(x);			// ������ �������� �� ������ ��������


	// �������� ��������� � �������
		cout << setprecision(5) << setw(7) << x << "  " << setprecision(5) << setw(13) << series << "  " << setprecision(5) << setw(13) << func << "  " << setprecision(5) << setw(18) << fabs(series - func) << "  " << setw(7) << n << endl;

		// �������� ��������� � ����


		fprintf(file, "%f %f %f %f %i\n", x, series, func, fabs(series - func), n);

		x += delta;
	}


	fclose(file);
	cout << endl << "The result was saved to a file " << '"' << "out.txt" << '"' << endl;
}

// ������� ���������� � ������, ������ ��������� �� ���� ��� ����������
void readConsole(double& xBegin, double& xEnd, double& delta, double& eps)
{
	cout << "begin: ";
	cin >> xBegin;

	cout << "end: ";
	cin >> xEnd;

	cout << "Delta: ";
	cin >> delta;

	cout << "Epsilon (1, 0.1, 0.001): ";
	cin >> eps;
}

// ������� ���������� � �����, ������ ��������� �� ���� ��� ����������
void readFile(double& xBegin, double& xEnd, double& delta, double& eps)
{
	char* fileName = new char();
	cout << "Enter file name: ";	// ������� �����
	cin >> fileName;				// �������� �����

	FILE* file;
	fopen_s(&file, fileName, "r"); // ��������� ����
	if (file == nullptr)
	{
		cout << "Invalid file name!\n";
		return;
	}


	float xB, xE, d, e;

	fscanf_s(file, "%f%f%f%f", &xB, &xE, &d, &e); // ������� ���� � �����
	xBegin = xB;
	xEnd = xE;
	delta = d;
	eps = e;

	fclose(file); // ��������� ����
}

// ������� ������� true ���� �� ���� ���������� ������� �� false 
bool validation(double xBegin, double xEnd, double delta, double eps)
{
	if ((((xEnd - xBegin) > delta) && (delta < 0)) ||
		((xBegin == xEnd) && delta != 0.0) ||
		(xEnd < xBegin) || (eps <= 0.0) || (eps > 1.0))

		return false; // ���� �� �����

	return true; // ���� �����
}
