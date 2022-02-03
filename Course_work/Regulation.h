#pragma once
#ifndef REGULATION
#define REGULATION

#include "Task.h"

//���� ������� ������������ ����� Task
class Regulation : public Task
{
public:
	Regulation();
	Regulation(string _taskName, string _executorName, string _Firma, int _daysOnTask, string _kindRegTask, int _amountComplTask);

	~Regulation();

	void			setKindRegTask(const string _kindRegTask);
	const string	getKindRegTask() const;

	void			setAmountComplTask(const int _amountComplTask);
	const int		getAmountComplTask() const;

	virtual void show() const;
	virtual	bool isGuarantee();
	virtual	bool isRegulation();

	virtual ofstream& returned(ofstream& out, const Task* data) const;
	virtual	Task& input(ifstream& in, Task* object) const;
	friend ofstream& operator << (ofstream& out, const Regulation* data);
	friend Task& operator >> (ifstream& in, Regulation* object);

private:
	string kindRegTask;//��� ��������������
	int amountComplTask;//ʳ-�� ��������� �����
};

#endif