#include <iostream>
#include "conio.h"
#include <ctime>
using namespace std;
struct stack
{
	int data;
	stack* next;
};
void push(stack** a, int elem)
{
	stack* k = new stack;
	k->data = elem;
	if (a != NULL)
		k->next = *a;
	*a = k;
}

int pop(stack** head)
{
	if (*head != NULL)
	{
		int tmp = (*head)->data;
		stack* p_tmp = *head;
		*head = (*head)->next;
		delete p_tmp;
		return tmp;
	}
}
void more_average(stack** head, float* average_elem = 0)
{
	int k = 0, temp = 0;
	stack* head2 = NULL;
	while (*head != NULL)
	{
		temp = pop(head);
		*average_elem += temp;
		push(&head2, temp);
		k++;
	}
	(*average_elem) /= k;
	k = 0;
	while (head2 != NULL)
	{
		temp = pop(&head2);
		push(head, temp);
		if (temp > * average_elem)
			push(&head2, temp);
	}
}
int average(stack** of)
{
	double average = 0;
	int n = 0;
	for (*of != NULL; (*of) = (*of)->next;)
	{
		average += (*of)->data;
		n++;
	}
	double k = average / n;
	cout << "Avg: " << k << endl;
	return k;
}


void swap(stack** inpt, stack** of)
{
	double avg = 0;
	int n = 0;
	for (*of != NULL; (*of) = (*of)->next;)
	{
		avg += (*of)->data;
		n++;
	}
	double k = avg / n;
	cout << "Avg: " << k << endl;

	double tmp = pop(of);
	while (*of != NULL)
	{
		if (tmp >= avg)
		{
			push(inpt, tmp);
		}
		tmp = pop(of);
	}
	if (tmp >= avg)
	{
		push(inpt, tmp);
	}

}
void disp(stack* k)
{
	for (; k != NULL; k = k->next)
		cout << k->data << " ";
}
void del(stack** k)
{
	while (*k != NULL)
	{
		stack* a = (*k)->next;
		delete* k;
		*k = a;
	}
}
void vvod(stack** a, int* array, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		array[i] = rand() % 50 - 25;

	for (int i(0); i < n; i++)
		push(a, array[i]);
}
int main()
{
	stack* head1 = NULL;
	stack* head2 = NULL;
	int n = 0;
	cout << "Enter n: ";
	cin >> n;
	int* array = new int[n];
	vvod(&head1, array, n);
	cout << "Stack: ";
	disp(head1);
	cout << endl << "NewStack: ";
	swap(&head2, &head1);
	disp(head2);
	disp(head1);
	del(&head1);
	del(&head2);
	delete[] array;
	_getch();
	return 0;
}
