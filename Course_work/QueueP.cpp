#include "QueueP.h"

QueueP::QueueP() : head(NULL), tail(NULL), amount(0) {}

QueueP::~QueueP() {}

bool	QueueP::isEmpty()
{
	return head == NULL;
}

int		QueueP::getAmount() { return amount; }//кі-ть елементів

void	QueueP::Push(Task* data)//створення елементу
{
	string trash;
	int _priority = 0;
	cout << "Input priority for new element: ";
	getline(cin, trash, '\n');
	_priority = atoi(trash.c_str());
	Queue* cptail = tail;
	Queue* newData = new Queue;
	newData->data = data;
	newData->next = NULL;
	newData->priority = _priority;
	if (head == NULL)
	{
		head = newData;
		tail = newData;
	}
	else
	{
		tail->next = newData;
		tail = tail->next;
	}
	amount++;
	cout << endl << "New element successfully add..." << endl;
}

bool	QueueP::CompareElements(Queue* elementOne, Queue* elementTwo)//порівняння елементів
{
	return elementOne->priority > elementTwo->priority;
}

Task* QueueP::Pop()//видалення елемента
{
	if (isEmpty())
	{
		cout << "Container is empty..." << endl;
		return NULL;
	}
	Queue* popElement = head;
	Queue* cpHead = head;
	while (cpHead->next)
	{
		if (CompareElements(popElement, cpHead->next))
			popElement = cpHead->next;
		cpHead = cpHead->next;
	}
	cpHead = head;
	Queue* popElementNext = popElement->next;
	if (popElement == head)
	{
		head = head->next;
		popElement->next = NULL;
		if (tail == popElement)
			tail = head;
	}
	else if (popElement == tail)
	{
		while (cpHead->next != tail)
			cpHead = cpHead->next;
		tail = cpHead;
		tail->next = NULL;
	}
	else
	{
		while (cpHead->next != popElement)
			cpHead = cpHead->next;

		cpHead->next = popElementNext;
		popElement->next = NULL;
	}
	Task* data = popElement->data;
	delete popElement;
	amount--;
	cout << "Element successfully remove..." << endl;
	return data;
}

void	QueueP::Clean()//очищення черги
{
	while (!isEmpty())
		Pop();
	cout << "All elements successfully remove..." << endl;
}

void	QueueP::Show()//вивід черги
{
	Queue* cpHead = head;
	if (isEmpty())
		cout << "Container is empty..." << endl;
	while (cpHead)
	{
		cout << "Priority: " << cpHead->priority << endl;
		cpHead->data->show();
		cpHead = cpHead->next;
		cout << endl;
	}
}

int		QueueP::MainTask()
{
	int count = 0;
	string firm;
	cout << "Input Firm: ";
	getchar();
	getline(cin, firm, '\n');
	Queue* cpHead = head;
	while (cpHead)
	{
		if (cpHead->data->getFirma() == firm && cpHead->data->isGuarantee())
			count++;
		cpHead = cpHead->next;
	}
	return (count);
}


void	QueueP::Sort()//сортування елементів
{
	Task* swap;
	int swap_priority;
	Queue* cpHead = head;
	if (isEmpty())
	{
		cout << "Container is empty..." << endl;
		return;
	}
	while (head->next)
	{
		if (!CompareElements(head, head->next))
		{
			swap = head->data;
			swap_priority = head->priority;
			head->data = head->next->data;
			head->priority = head->next->priority;
			head->next->data = swap;
			head->next->priority = swap_priority;
			head = cpHead;
		}
		else
			head = head->next;
	}
	head = cpHead;
	cout << "Elements was sorted..." << endl;
}

ofstream& operator << (ofstream& out, Queue* head)
{
	while (head)
	{
		head->data->returned(out, head->data);
		head = head->next;
	}
	return out;
}

void	QueueP::WriteInFile() //запис у файл
{
	if (isEmpty())
	{
		cout << "Container is empty..." << endl;
		return;
	}
	ofstream out("Task.txt");
	if (!out.is_open())
	{
		cout << "Cant open file" << endl;
		return;
	}
	out << head;
	out.close();
	cout << "Successful saving to file" << endl;
}

Task& operator>>(ifstream& in, Task& object)
{
	object.input(in, &object);
	return (object);
}

int		QueueP::ReadFromFile(QueueP Container)//зчитування
{
	ifstream in;
	in.open("Task.txt");
	if (!in.is_open())
	{
		cout << "Error opening file!" << endl;
		return (0);
	}

	int k;
	int count = 0;
	while (in >> k)
	{
		string trash;
		getline(in, trash);
		if (k == 1)
		{
			Task* T = new Guarantee;
			in >> *T;
			Container.Push(T);
			count++;
		}
		else if (k == 2)
		{
			Task* T = new Regulation;
			in >> *T;
			Container.Push(T);
			count++;
		}
	}
	*this = Container;
	return (count);
}