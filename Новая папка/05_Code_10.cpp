#include <iostream>
using namespace std;
void vvodmasiva(int A[], int size) //������� ����� ������.�� ���� �������� ����� ������
{
	for (int i = 0; i < size; i++)
	{
		cout << "input A[" << i << "] = ";
		cin >> A[i];
	}
}
/*������� , ��� �������� ��
*�������� ������ �� ���� �� ������� ,
*� ������ ���� ������ � ��������.�� ���� �������� ����� ������*/
void ssuvmassiva(int A[], int size)
{
	cout << "\n new massiv ";
	int tamp = A[0];
	for (int i = 1; i < size; i++)
	{
		A[i - 1] = A[i];
	}
	A[size - 1] = tamp;

}
//������� ������ ������ ������.�� ���� �������� ����� ������
void vuvodmasiva(int A[], int size)
{
	for (int i = 0; i < size; ++i)
		cout << A[i] << " ";
}
void main()
{
	int n = 0;
	cout << "Enter n: ";
	cin >> n;
	int* arr = new int[n];
	vvodmasiva(arr, n);
	vuvodmasiva(arr, n);
	ssuvmassiva(arr, n);
	vuvodmasiva(arr, n);
	delete[] arr;
}
