#include <iostream>
#include "conio.h"
using namespace std;

struct Station
{
	char name_city[64];
	char code_city[64];
	char data[64];
	float  time_zvonka = 0;
	int    tarif = 0;
	char   number_abonenta[64];
};

void chas_rozmov(Station* a, char* name_city)
{
	float result = 0;
	float sum = 0;
	for (int i = 0; i < 9; i++)
		if (strcmp(name_city, a[i].name_city) == 0)
		{
			sum += a[i].time_zvonka * a[i].tarif;
			result += a[i].time_zvonka;
		}
	cout << "Full time of talking : " << result << " Minutes" << endl;
	cout << "Summa : " << sum << " UAH" << endl;
}
int main()
{
	Station a[9] =
	{
		{"Kyiv",		"03134"	,	"30.10.2019",	12.00,	2,	"380675881365"},
		{"Vinnytsia",	"21000" ,	"20.09.2019",	16.00,	2,	"380675881366"},
		{"Kharkiv",		"61000" ,	"12.07.2019",	10.00,	1,	"380675881367"},
		{"Odessa",		"65001" ,	"24.05.2019",	9.00,	3,	"380675881368"},
		{"Harkiv",		"61000" ,	"11.11.2019",	8.00,	2,	"380675881369"},
		{"Kyiv",		"03134" ,	"20.09.2019",	20.00,	1,	"380675881370"},
		{"Odessa",		"65001" ,	"10.10.2019",	7.00,	3,	"380675881371"},
		{"Kharkiv",		"61000" ,	"09.09.2019",	6.00,	2,	"380675881372"},
		{"Kharkiv",		"61000" ,	"12.12.2019",	4.00,	3,	"380675881367"},
	};

	char name_city[64];
	cout << "input city: ";
	cin >> name_city;
	chas_rozmov(a, name_city);
	system("pause");
	return 0;
}
