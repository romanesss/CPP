#include "Guarantee.h"

Guarantee::Guarantee() : Task(), timeUsed(0), timeLeftGuar(0) {}//конструктор
Guarantee::Guarantee(string _taskName, string _executorName, string _Firma, int _daysOnTask, int _timeUsed, int _timeLeftGuar) :
	Task(_taskName, _executorName, _Firma, _daysOnTask), timeUsed(_timeUsed), timeLeftGuar(_timeLeftGuar) {}

Guarantee::~Guarantee() {}

void		Guarantee::setTimeUsed(const int _timeUsed) { timeUsed = _timeUsed; }
const int	Guarantee::getTimeUsed() const { return timeUsed; }

void		Guarantee::setTimeLeftGuar(const int _timeLeftGuar) { timeLeftGuar = _timeLeftGuar; }
const int	Guarantee::getTimeLeftGuar() const { return timeUsed; }

void Guarantee::show() const//вивід
{
	cout << "----Guarantee Task----" << endl;
	Task::show();
	cout << "Time Used: " << timeUsed << endl <<
		"Time Left Guar: " << timeLeftGuar << endl;
}

bool Guarantee::isGuarantee() { return true; }

bool Guarantee::isRegulation() { return false; }

ofstream& operator << (ofstream& out, const Guarantee* data)
{
	out << data->getTimeUsed() << endl;
	out << data->getTimeLeftGuar() << endl;

	return (out);
}

ofstream& Guarantee::returned(ofstream& out, const Task* data) const
{
	out << 1 << endl;
	Task::returned(out, data);
	out << (Guarantee*)data;
	return (out);
}

Task& operator >> (ifstream& in, Guarantee* object)
{
	int _timeUsed;
	int	_timeLeftGuar;

	in >> _timeUsed;
	in >> _timeLeftGuar;
	object->setTimeUsed(_timeUsed);
	object->setTimeLeftGuar(_timeLeftGuar);

	return (*object);
}

Task& Guarantee::input(ifstream& in, Task* object) const
{
	Task::input(in, object);
	in >> (Guarantee*)object;
	return (*object);
}