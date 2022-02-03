#pragma once
#pragma once
#ifndef QUEUEP
#define QUEUEP

#include "Task.h"
#include "Guarantee.h"
#include "Regulation.h"

struct Queue
{
	Task* data;
	Queue* next;
	int		priority;
};

class QueueP
{
public:
	QueueP();
	~QueueP();

	bool	isEmpty();
	int		getAmount();
	bool	CompareElements(Queue* elementOne, Queue* elementTwo);

	void	Push(Task* data);
	Task* Pop();
	void	Clean();

	void	Show();

	int		MainTask();
	void	Sort();

	void	WriteInFile();
	int		ReadFromFile(QueueP Container);

	friend ofstream& operator<<(ofstream&, Queue*);

	friend Task& operator>>(ifstream& in,
		Task& object);

private:
	Queue* head;//покажчик на перший елемент
	Queue* tail;//покажчик на останній елемент
	int		amount;//кі-ть елементів
};

#endif