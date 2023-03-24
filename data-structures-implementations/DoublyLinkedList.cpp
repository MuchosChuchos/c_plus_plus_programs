#include <iomanip>
#include <iostream>
#include <Windows.h>
#include<conio.h>
using namespace std;

struct Node
{
  char inf;
  Node *next, *prev;
};
void Init();
int Size();
void Push_L(char);
void Push_R(char);
bool Pop_L(char *);
bool Pop_R(char *);
Node *Find(char);
void Clear();
void List();
Node *pbeg,*pend;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char key, s;
	bool flag;
	
label:
	system("cls");
	cout << "0 - ²í³ö³àë³çóâàòè" << endl << "1 - Äîäàòè çë³âà" << endl;
	cout << "2 - Äîäàòè ñïðàâà" << endl << "3 - Âèòÿãíóòè çë³âà" <<endl;
	cout << "4 - Âèòÿãíóòè ñïðàâà" << endl << "5 - Ðîçì³ð" << endl;
	cout << "6 - Ïåðåãëÿíóòè" << endl << "7 - Î÷èùåííÿ" << endl;
	cout << "8 - Ïîøóê ïî êëþ÷ó" << endl <<"9 - Âèõ³ä"<< endl << "ÇÐÎÁ²ÒÜ ÂÈÁ²Ð --> ";
	key = _getch();
	switch (key)
	{
	case '0':
	{
		system("cls");
		cout << "²í³ö³àë³çóºìî" << endl;
		Init();
		system("pause");
		goto label;
	}
	case '1':
	{
		system("cls");
		cout << "ÄÎÄÀªÌÎ ÇË²ÂÀ" << endl;
		cout << "Ââåä³òü çíà÷åííÿ åëåìåíòà?->";
		cin >> s;
		Push_L(s);
		system("pause");
		goto label;
	}
	case '2':
	{
		system("cls");
		cout << "ÄÎÄÀªÌÎ CÏÐÀÂÀ" << endl;
		cout << "Ââåä³òü çíà÷åííÿ åëåìåíòà?->";
		cin >> s;
		Push_R(s);
		system("pause");
		goto label;
	}
	case '3':
	{
		system("cls");
		cout << "ÂÈÒßÃÓªÌÎ ÇË²ÂÀ" << endl;
		flag=Pop_L(&s);
		if (!flag)
		{
			cout << "Ñïèñîê ïîðîæí³é!\n";
		}
		else
			cout << "Âèòÿãíóëè ç ñïèñêà->"<<s<<endl;
		system("pause");
		goto label;
	}
	case '4':
	{
		system("cls");
		cout << "ÂÈÒßÃÓªÌÎ ÑÏÐÀÂÀ" << endl;
		flag=Pop_R(&s);
		if (!flag)
		{
			cout << "Ñïèñîê ïîðîæí³é!\n";
		}
		else
			cout << "Âèòÿãíóëè ç ñïèñêà->"<<s<<endl;
		system("pause");
		goto label;
	}
	case '5':
	{
		system("cls");
		cout << "ÐÎÇÌ²Ð" << endl;
		cout << "Ðîçì³ð ñïèñêà = " << Size() << endl;
		system("pause");
		goto label;
	}
	case '6':
	{
		system("cls");
		cout << "ÏÅÐÅÃËßÄ ÂÌ²ÑÒÓ" << endl;
		List();
		system("pause");
		goto label;
	}
	case '7':
	{
		system("cls");
		cout << "Î×ÈÙÅÍÍß" << endl;
		Clear();
		system("pause");
		goto label;
	}
	/*case '6':
	{
		system("cls");
		cout << "Ïîøóê ïî êëþ÷ó" << endl;
		cout << "Ââåä³òü êëþ÷ ïîøóêó -> ";
		key = _getch();
		SSll* dop = Find(baryer, key);
		if (dop)
			cout << "Åëåìåíò çíàéäåìî, â³í = " << dop->inf << endl;
		else
			cout << "Åëåìåíò â ñòðóêòóð³ â³äñóòí³é!" << endl;
		system("pause");
		goto label;
	}*/
	case '9':
	{
		system("cls");
		cout << "Âñåãî äîðáîãî!" << endl;
		system("pause");
		return 0;
	}
	default:
	{
		cout << endl << "ÍÅÏÐÀÂÈËÜÍÈÉ ÂÈÁ²Ð" << endl;
		system("pause");
		goto label;
	}
	}
	system("pause");
	return 0;
}

void Init()
{
	pbeg=NULL;
	pend=NULL;
}

void Push_L(char a)
{
	Node* temp = new Node;
	temp->inf = a;
	if (Size()==0)
	{
		temp->next = 0;
		temp->prev = 0;
		pbeg=temp;
		pend=temp;
	}
	else
	{
		temp->next = pbeg;
		temp->prev = 0;
		pbeg->prev=temp;
		pbeg=temp;
	}
}

void Push_R(char a)
{
	Node* temp = new Node;
	temp->inf = a;
	if (Size()==0)
	{
		temp->next = 0;
		temp->prev = 0;
		pend=temp;
		pbeg=temp;
	}
	else
	{
		temp->next = 0;
		temp->prev = pend;
		pend->next=temp;
		pend=temp;
	}
}

int Size()
{
	Node *temp;
	temp = pbeg;
	if(!temp)
		return 0;
	int k=1;
	while(temp->next)
	{
		temp=temp->next;
		k++;
	}
	return k;
}

bool Pop_L(char *a)
{
	if(Size()==0) return false;
	Node *temp=pbeg;
	*a=temp->inf;
	if(Size()==1)
	{
		delete(temp);
		pbeg=NULL;
		pend=NULL;
	}
	else{
		temp->next->prev=NULL;
		pbeg=temp->next;
		delete(temp);
	}
	return true;
}

bool Pop_R(char *a)
{
	if(Size()==0) return false;
	Node *temp=pbeg;
	*a=temp->inf;
	if(Size()==1)
	{
		delete(temp);
		pbeg=NULL;
		pend=NULL;
	}
	else{
		pend->prev->next=NULL;
		pend=pend->prev;
		delete(temp);
	}
	return true;
}


void List()
{
	Node *temp = pbeg;
	if (!temp)
		cout << "Ñòðóêòóðà ïîðîæíÿ!!!\n";
	else
	{
		while(temp)
		{
			cout<<temp->inf<<" ";
			temp=temp->next;
		}
	}
	cout<<endl;
}

void Clear()
{
	char d;
	while(Size()!=0)
		Pop_R(&d);
}
