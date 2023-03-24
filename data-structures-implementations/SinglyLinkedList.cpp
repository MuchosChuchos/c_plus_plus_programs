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
	cout << "0 - Ініціалізувати" << endl << "1 - Додати" << endl;
	cout << "2 - Витягнути" << endl << "3 - Розмір" << endl;
	cout << "4 - Переглянути" << endl << "5 - Очищення" << endl;
	cout << "6 - Пошук по ключу" << endl <<"7 - Вихід"<< endl << "ЗРОБІТЬ ВИБІР --> ";
	key = _getch();
	switch (key)
	{
	case '0':
	{
		system("cls");
		cout << "Ініціалізуємо" << endl;
		if (baryer = Init())
			cout << "Ініціалізовано успішно\n";
		else
			cout << "Не успішно\n";
		system("pause");
		goto label;
	}
	case '1':
	{
		system("cls");
		cout << "ДОДАЄМО" << endl;
		cout << "Введіть значення елемента?->";
		cin >> s;
		Push(&baryer, s);
		system("pause");
		goto label;
	}
	case '2':
	{
		system("cls");
		cout << "Витягаємо" << endl;
		if (!Empty(&baryer))
		{
			s = Pop(&baryer);
			cout << "Витягнуто -> " << s << endl;
		}
		else
			cout << "Структура порожня!\n";
		system("pause");
		goto label;
	}
	case '3':
	{
		system("cls");
		cout << "РОЗМІР" << endl;
		cout << "Розмір структури = " << Size(&baryer) << endl;
		system("pause");
		goto label;
	}
	case '4':
	{
		system("cls");
		cout << "ПЕРЕГЛЯД ВМІСТУ" << endl;
		List(&baryer);
		system("pause");
		goto label;
	}
	case '5':
	{
		system("cls");
		cout << "ОЧИЩЕННЯ" << endl;
		Clear(&baryer);
		system("pause");
		goto label;
	}
	case '6':
	{
		system("cls");
		cout << "Пошук по ключу" << endl;
		cout << "Введіть ключ пошуку -> ";
		key = _getch();
		SSll* dop = Find(baryer, key);
		if (dop)
			cout << "Елемент знайдемо, він = " << dop->inf << endl;
		else
			cout << "Елемент в структурі відсутній!" << endl;
		system("pause");
		goto label;
	}
	case '7':
	{
		system("cls");
		cout << "Всего дорбого!" << endl;
		system("pause");
		return 0;
	}
	default:
	{
		cout << endl << "НЕПРАВИЛЬНИЙ ВИБІР" << endl;
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
		cout << "Структура порожня!!!\n";
	else
	{
		SSll* temp = new SSll;
		temp = (*beg)->next;
		cout << "Елементи структури:\n";
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
