#include <iomanip>
#include <iostream>
#include <Windows.h>
#include <conio.h>

typedef char data;

struct SSll
{
	data inf;
	SSll* next;
}*baryer;

SSll* Init();
bool Empty(SSll**);
void Push(SSll**, data);
data Pop(SSll**);
void List(SSll** const);
int Size(SSll**);
void Clear(SSll**);
SSll* Find(SSll*, data);

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char key;
	data s;
label:
	system("cls");
	cout << "0 - ������������" << endl << "1 - ������" << endl;
	cout << "2 - ���������" << endl << "3 - �����" << endl;
	cout << "4 - �����������" << endl << "5 - ��������" << endl;
	cout << "6 - ����� �� �����" << endl <<"7 - �����"<< endl << "������� ����� --> ";
	key = _getch();
	switch (key)
	{
	case '0':
	{
		system("cls");
		cout << "����������" << endl;
		if (baryer = Init())
			cout << "������������ ������\n";
		else
			cout << "�� ������\n";
		system("pause");
		goto label;
	}
	case '1':
	{
		system("cls");
		cout << "�������" << endl;
		cout << "������ �������� ��������?->";
		cin >> s;
		Push(&baryer, s);
		system("pause");
		goto label;
	}
	case '2':
	{
		system("cls");
		cout << "��������" << endl;
		if (!Empty(&baryer))
		{
			s = Pop(&baryer);
			cout << "��������� -> " << s << endl;
		}
		else
			cout << "��������� �������!\n";
		system("pause");
		goto label;
	}
	case '3':
	{
		system("cls");
		cout << "���̲�" << endl;
		cout << "����� ��������� = " << Size(&baryer) << endl;
		system("pause");
		goto label;
	}
	case '4':
	{
		system("cls");
		cout << "�������� �̲���" << endl;
		List(&baryer);
		system("pause");
		goto label;
	}
	case '5':
	{
		system("cls");
		cout << "��������" << endl;
		Clear(&baryer);
		system("pause");
		goto label;
	}
	case '6':
	{
		system("cls");
		cout << "����� �� �����" << endl;
		cout << "������ ���� ������ -> ";
		key = _getch();
		SSll* dop = Find(baryer, key);
		if (dop)
			cout << "������� ��������, �� = " << dop->inf << endl;
		else
			cout << "������� � �������� �������!" << endl;
		system("pause");
		goto label;
	}
	case '7':
	{
		system("cls");
		cout << "����� �������!" << endl;
		system("pause");
		return 0;
	}
	default:
	{
		cout << endl << "������������ �����" << endl;
		system("pause");
		goto label;
	}
	}
	system("pause");
	return 0;
}

SSll* Init()
{
	SSll* temp = new SSll;
	temp->next = temp;
	return temp;
}

bool Empty(SSll** s)
{
	return ((*s)->next == *s) ? true : false;
}

void Push(SSll** beg, data c)
{
	SSll* temp = new SSll;
	temp->inf = c;
	if (Empty(beg))
	{
		temp->next = *beg;
		(*beg)->next = temp;
	}
	else
	{
		temp->next = (*beg)->next;
		(*beg)->next = temp;
	}
}

int Size(SSll** beg)
{
	if (Empty(beg))
		return 0;
	else
	{
		int count = 0;
		SSll* temp = new SSll;
		temp = *beg;
		while(temp->next != *beg)
		{
			temp = temp->next;
			count++;
		}
		delete[] temp;
		return count;
	}
}

data Pop(SSll** beg)
{
	if(!Empty(beg))
	{
		SSll* temp = (*beg)->next;
		data c = temp->inf;
		(*beg)->next = temp->next;
		delete temp;
		return c;
	}
}

void List(SSll** const beg)
{
	if (Empty(beg))
		cout << "��������� �������!!!\n";
	else
	{
		SSll* temp = new SSll;
		temp = (*beg)->next;
		cout << "�������� ���������:\n";
		while(temp != *beg)
		{
			cout << temp->inf;
			temp = temp->next;
		}
	}
}

void Clear(SSll** beg)
{
	data c;
	while (!Empty(beg))
		c = Pop(beg);
}

SSll* Find(SSll*beg, data key)
{
	if (!Empty(&beg)) 
		return 0;
	SSll* temp = beg->next;
	while(temp != beg)
	{
		if (temp->inf == key)
			return temp;
		temp = temp->next;
	}
	return 0;
}
