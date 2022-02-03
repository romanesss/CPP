//Koä:
#include <iostream>
using namespace std;
int getNextGap(int gap)
{

	gap = (gap * 41) / 13;

	if (gap < 1)
		return 1;
	return gap;
}

void combSort(int a[], int n)
{

	int gap = n;


	bool swapped = true;


	while (gap != 1 || swapped == true) {

		gap = getNextGap(gap);


		swapped = false;


		for (int i = 0; i < n - gap; i++) {
			if (a[i] % 2 == 0) {
				if (a[i] < a[i + gap]) {
					swap(a[i], a[i + gap]);
					swapped = true;
				}
			}
		}
	}
}
void vuvod(int a[], int n)
{

	for (int i = 0; i < n; i++)
		cout << " " << a[i];

}
int main()
{
	//int a[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40 };
	int a[] = { 11,22,43,14,50,62,71,82,94,150,121,112,123,104,25,36,27,9,1,23,300,220,230,224,215,216,247,258,239,310,321,342,353,346,365,376,387,389,309,480 };
	int n = sizeof(a) / sizeof(*a);
	vuvod(a, n);
	combSort(a, n);

	cout << ("Sorted array: \n");
	vuvod(a, n);

	return 0;
}
