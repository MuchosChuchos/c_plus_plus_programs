#include<iostream>
#include<conio.h>
#include<Windows.h>
#include "Queue.h"
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	char punkt;
	int n;
	cout<<"������ ����� �����?->";
	cin>>n;
	Queue fifo(n);
	data s;
	label1:
		system("cls");
		cout<<"0-��������� �����"<<endl;
		cout<<"1-����������� � �����"<<endl<<"2-��������� �� �����"<<endl;
		cout<<"3-��������� �����"<<endl<<"4-����������� ����"<<endl;
		cout<<"5-�������� �����"<<endl<<"6-��� ��������"<<endl;
		cout<<"7-�����"<<endl<<endl<<"������� �����->";
		punkt=getche();
		switch(punkt)
		{
			case'0':
				{
					system("cls");
					cout<<"\t����������� ��ϲ������\n"<<endl;
					Queue fifo1(fifo);
					cout<<"�������"<<endl;
					fifo.List();
					cout<<"����"<<endl;
					fifo1.List();
					system("pause");
					goto label1;
				}
			case'1':
				{
					system("cls");
					cout<<"\t�������Ӫ�� � �����\n"<<endl;
					cout<<"������ �������� ��������?->";
					s=getche();
					fifo.Push(s);
					cout<<endl;
					system("pause");
					goto label1;
				}
			case'2':
				{
					system("cls");
					cout<<"\t�����Ӫ�� �� �����\n"<<endl;
					if(!fifo.Empty())
					{
						s=fifo.Pop();
						cout<<"� ����� ���������->\n"<<s;
					}else{
						cout<<"����� �������!\n";
					}
					system("pause");
					goto label1;
				}
			case'3':
				{
					system("cls");
					cout<<"\t���������� ���̲��\n"<<endl;
					cout<<"����� �����="<<fifo.Size()<<endl;
					system("pause");
					goto label1;
				}
			case'4':
				{
					system("cls");
					cout<<"\t�������� �����\n"<<endl;
					fifo.List();
					system("pause");
					goto label1;
				}
			case'5':
				{
					system("cls");
					cout<<"\t�������� �����\n"<<endl;
					fifo.Clear();
					system("pause");
					goto label1;
				}
			case'6':
				{
					system("cls");
					cout<<"��� ��������"<<endl;
					system("pause");
					goto label1;
				}
			case'7':
				{
					system("cls");
					fifo.~Queue();
					cout<<endl<<"������ �������� ���������!"<<endl<<"����� ��������!"<<endl;
					system("pause");
					return 0;
				}
			default:
				{
					cout<<endl<<"������������ �����"<<endl;
					system("pause");
					goto label1;
				}
		}
}
