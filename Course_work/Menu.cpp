#include "Menu.h"
#include "Guarantee.h"
#include "Regulation.h"

Menu* Menu::_self(0);

Menu* Menu::CreateMenu()
{
	if (!_self)
		_self = new Menu();
	return _self;
}

bool Menu::RemoveMenu()
{
	if (_self)
	{
		delete _self;
		_self = 0;
		return true;
	}
	return false;
}

void	Menu::Begin()
{
	int n = 0;
	int count;
	string str;

	Task* data;

	string taskName;
	string executorName;
	string Firma;
	int	daysOnTask;

	string trash;

	int timeUsed;
	int timeLeftGuar;

	string kindRegTask;
	int amountComplTask;
	do
	{
		system("cls");
		cout << "--------------- MENU ---------------" << endl;
		cout << "<1>.Create Guarantee`s object" << endl;
		cout << "<2>.Create Regulatio`s object" << endl;
		cout << "<3>.Remove low prioritet Task" << endl;
		cout << "<4>.Show all Task" << endl;
		cout << "<5>.Remove all Task" << endl;
		cout << "<6>.Save in file" << endl;
		cout << "<7>.Read from file" << endl;
		cout << "<8>.Sort" << endl;
		cout << "<9>.Do main task" << endl;
		cout << "<10>.Exit" << endl << endl;

		cout << "Input choise: ";
		cin >> str;
		n = atoi(str.c_str());
		switch (n)
		{
		case 1:
			system("cls");
			cout << "Task name: ";
			getchar();
			getline(cin, taskName, '\n');
			cout << "Executor name: ";
			getline(cin, executorName, '\n');
			cout << "Firma: ";
			getline(cin, Firma, '\n');
			cout << "Days on task: ";
			getline(cin, trash, '\n');
			daysOnTask = atoi(trash.c_str());
			cout << "Time Used: ";
			getline(cin, trash, '\n');
			timeUsed = atoi(trash.c_str());
			cout << "Time Left Guar: ";
			getline(cin, trash, '\n');
			timeLeftGuar = atoi(trash.c_str());

			data = new Guarantee(taskName, executorName, Firma, daysOnTask, timeUsed, timeLeftGuar);
			Container.Push(data);//створення гарантійного об'єкта
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "Task name: ";
			getchar();
			getline(cin, taskName, '\n');
			cout << "Executor name: ";
			getline(cin, executorName, '\n');
			cout << "Firma: ";
			getline(cin, Firma, '\n');
			cout << "Days on task: ";
			getline(cin, trash, '\n');
			daysOnTask = atoi(trash.c_str());
			cout << "Kind Regulation Task: ";
			getline(cin, kindRegTask, '\n');
			cout << "Amount Complete Task: ";
			getline(cin, trash, '\n');
			amountComplTask = atoi(trash.c_str());

			data = new Regulation(taskName, executorName, Firma, daysOnTask, kindRegTask, amountComplTask);
			Container.Push(data);//створення об'єкта регламентного обслуговування
			system("pause");
			break;
		case 3:
			system("cls");
			Container.Pop();//видалення елемента
			system("pause");
			break;
		case 4:
			system("cls");
			Container.Show();//вивід контейнера
			system("pause");
			break;
		case 5:
			system("cls");
			Container.Clean();//очищення контейнера
			system("pause");
			break;
		case 6:
			system("cls");
			Container.WriteInFile();//запис у файл
			system("pause");
			break;
		case 7:
			system("cls");
			Container.ReadFromFile(Container);//зчитування з файлу
			system("pause");
			break;
		case 8:
			system("cls");
			Container.Sort();//сортування
			system("pause");
			break;
		case 9:
			system("cls");
			count = Container.MainTask();//основне завдання
			cout << "The total number of warranty repairs of a given company: " << count << endl;
			system("pause");
			break;
		case 10:
			system("cls");
			Container.Clean();//вихід
			cout << "The program has completed..." << endl;
			break;
		default:
			cout << "Bad input. Try again..." << endl;;
			system("pause");
			break;
		}

	} while (n != 10);
}