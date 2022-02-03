#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <string>

using namespace std;

double getRec(double, int); // повертає рекурентний множник
long double getValue(double); // повертає табличне значення
long double getSuma(double, double, double, int&); // рекурсивна функція яка повертає суму ряду
long double getSeriesSum(double, double, int&); // функція обрахунку суми
void calculate(double, double, double, double); // функція рахує і виводить значення
void readConsole(double&, double&, double&, double&); // читає з консолі
void readFile(double&, double&, double&, double&); // читає з файлу
bool validation(double, double, double, double); // перевірка валідності данних


int main()
{

	double begin = 0, end = 0, delta = 0, eps = 2; // змінні для зберігання вхідних данних
	int mode = 0;	// режим зчитування
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
	if (validation(begin, end, delta, eps)) // якщо данні валідні
		calculate(begin, end, delta, eps);	// запускаємо функцію 
	else // якщо данні не валідні
		cout << "Invalid values!" << endl;	// виводимо помилку
	system("pause");	// пауза, щоб консоль не закривалася
	return 0;
}

// Функція повертає кожну частку ряду, отримує х та номер елементу рядка
double getRec(double x, int n)
{
	return x / n; // формула частки для цього ряду
}

// Функція повертає точне значення нашої функції, отримує х
long double getValue(double x)
{
	return exp(x); // наша функція
}

// Рекурсивна функція обрахунку суми ряду
long double getSuma(double x, double el, double eps, int& n) {

	if (fabs(el) > eps) // умова виходу з рекурсії
	{
		n++;
		return el + getSuma(x, el * getRec(x, n), eps, n);
	}

	return 0; // вихід з рекурсії
}

// Функція повертає суму рядка, отримує х, допустиму похибку, посилання на лічильник елементів рядка
long double getSeriesSum(double x, double eps, int& n)
{



	n = 0;
	long double current = 1;
	long double prev = 0;
	long double sum = 0;

	sum = getSuma(x, current, eps, n);


	return sum; // повертаємо результат
}

// Функція рахує суми усіх рядів на проміжку від xBegin до xEnd з кроком - delta та похибкою - eps
void calculate(double xBegin, double xEnd, double delta, double eps)
{

	//	ofstream file("out.txt"); // відкриваємо файл для збереження результатів
	FILE* file;

	fopen_s(&file, "out.txt", "w");
	double x = xBegin;
	system("cls");

	cout << setw(7) << "X" << setw(15) << "SERIES" << setw(15) << "EXACT" << setw(20) << "ERROR" << setw(11) << "STEPS" << endl; // виводимо шапку таблиці в консоль


	while (x <= xEnd)
	{
		int n = 0;
		double series = 0;
		double func = 0;


		series = getSeriesSum(x, eps, n);	// рахуємо значення за допомогою рядка
		func = getValue(x);			// рахуємо значення за відомою функцією


	// виводимо результат в консоль
		cout << setprecision(5) << setw(7) << x << "  " << setprecision(5) << setw(13) << series << "  " << setprecision(5) << setw(13) << func << "  " << setprecision(5) << setw(18) << fabs(series - func) << "  " << setw(7) << n << endl;

		// виводимо результат в файл


		fprintf(file, "%f %f %f %f %i\n", x, series, func, fabs(series - func), n);

		x += delta;
	}


	fclose(file);
	cout << endl << "The result was saved to a file " << '"' << "out.txt" << '"' << endl;
}

// Функція зчитування з консолі, отримує посилання на змінні для зчитування
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

// Функція зчитування з файлу, отримує посилання на змінні для зчитування
void readFile(double& xBegin, double& xEnd, double& delta, double& eps)
{
	char* fileName = new char();
	cout << "Enter file name: ";	// зчитуємо назву
	cin >> fileName;				// вхідного файлу

	FILE* file;
	fopen_s(&file, fileName, "r"); // відкриваємо файл
	if (file == nullptr)
	{
		cout << "Invalid file name!\n";
		return;
	}


	float xB, xE, d, e;

	fscanf_s(file, "%f%f%f%f", &xB, &xE, &d, &e); // зчитуємо данні з файлу
	xBegin = xB;
	xEnd = xE;
	delta = d;
	eps = e;

	fclose(file); // закриваємо файл
}

// Функція повертає true якщо всі данні відповідають вимогам та false 
bool validation(double xBegin, double xEnd, double delta, double eps)
{
	if ((((xEnd - xBegin) > delta) && (delta < 0)) ||
		((xBegin == xEnd) && delta != 0.0) ||
		(xEnd < xBegin) || (eps <= 0.0) || (eps > 1.0))

		return false; // данні не валідні

	return true; // данні валідні
}
