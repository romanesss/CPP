#include <cstdio>
#include <time.h>
#include <iostream>


#pragma warning(disable : 4996)
using namespace std;
void make(char* name);
void read(char* name);
void write(const char* name, const char* name1, const char* name2);
int main()
{
	char name[] = "C:/Users/1/Desktop/F.txt";
	char name1[] = "C:/Users/1/Desktop/F_1.txt";
	char name2[] = "C:/Users/1/Desktop/F_2.txt";

	make(name);
	make(name1);
	make(name2);

	read(name);
	cout << endl;

	write(name, name1, name2);

	read(name1);
	cout << endl;
	read(name2);

	return 0;
}
void make(char* name)
{
	FILE* f = fopen(name, "wb");
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
	{
		int num = rand() % 100;
		fwrite(&num, sizeof(int), 1, f);
	}
	fclose(f);
}
void read(char* name)
{
	FILE* file = fopen(name, "rb");

	for (int num = 0; fread(&num, sizeof(int), 1, file); )
		cout << num << " ";
	fclose(file);
}
void write(const char* name, const char* name1, const char* name2)
{
	FILE* f = fopen(name, "rb");
	FILE* f1 = fopen(name1, "wb");
	FILE* f2 = fopen(name2, "wb");
	fseek(f, 0, SEEK_END);
	int k = ftell(f) / sizeof(int);
	fseek(f, 0, SEEK_SET);

	int* array = new int[k];

	fread(array, sizeof(int), k, f);

	for (int i = 0; i < k; i++)
		if (array[i] % 2 == 0)
			fwrite(&array[i], sizeof(int), 1, f1);
		else
			fwrite(&array[i], sizeof(int), 1, f2);

	fclose(f);
	fclose(f1);
	fclose(f2);
	delete[] array;
}
