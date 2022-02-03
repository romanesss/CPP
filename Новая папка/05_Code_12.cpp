#include <iostream>  
#include <cctype>  
#include <string.h>
#pragma warning(disable : 4996)

using namespace std;
int proverkaslov(int dlinna_stroki, char* slovo)
{
	char i = 0;
	for (int i = 0; i < dlinna_stroki; ++i)
		if (!isdigit(slovo[i]))
			return 0;
	return 1;
}
int  proverkanachislo(char text[])
{
	int num_is(0);
	char* razdel = strtok(text, " ");

	for (int i = 0; razdel != 0; i++)
	{

		{
			if (proverkaslov(strlen(razdel), razdel))
				num_is = 1;
			razdel = strtok(0, " ");
		}
	}

	return num_is;
}

int main() {
	char text[64] = "";
	cout << "vvedite text : ";

	cin.getline(text, sizeof(text));

	if (proverkanachislo(text))		cout << "v stroke est chislo" << endl;
	else		cout << "v stroke net chisla" << endl;

	system("PAUSE");
	return 0;
}
