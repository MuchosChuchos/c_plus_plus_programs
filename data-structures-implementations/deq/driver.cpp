#include<iostream>
#include<conio.h>
#include<Windows.h>
#include "Deq.h"
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	char punkt;
	int n;
	cout<<"������ ����� ����?->";
	cin>>n;
	Deq dek(n);
	data s;
	label1:
		system("cls");
		cout<<"0-��������� ����"<<endl;
		cout<<"1-����������� � ���� ����"<<endl<<"2-����������� � ���� ������"<<endl;
		cout<<"3-��������� �� ���� ���"<<endl<<"4-��������� �� ���� ������"<<endl;
		cout<<"5-��������� �����"<<endl<<"6-����������� ����"<<endl;
		cout<<"7-�������� ����"<<endl<<"8-��� ��������"<<endl;
		cout<<"9-�����"<<endl<<endl<<"������� �����->";
		punkt=getche();
		switch(punkt)
		{
			case'0':
				{
					system("cls");
					cout<<"\t����������� ��ϲ������\n"<<endl;
					Deq dek1(dek);
					cout<<"�������"<<endl;
					dek.List();
					cout<<"����"<<endl;
					dek1.List();                                       
					system("pause");
					goto label1;
				}
			case'1':
				{
					system("cls");
					cout<<"\t�������Ӫ�� � ���� �˲��\n"<<endl;
					cout<<"������ �������� ��������?->";
					s=getche();
					dek.Push_Left(s);
					cout<<endl;
					system("pause");
					goto label1;
				}
			case'2':
				{
					system("cls");
					cout<<"\t�������Ӫ�� � ���� ������\n"<<endl;
					cout<<"������ �������� ��������?->";
					s=getche();
					dek.Push_Right(s);
					cout<<endl;
					system("pause");
					goto label1;
					system("cls");
				}
			case'3':
				{
					system("cls");
					cout<<"\t�����Ӫ�� �� ���� �˲��\n"<<endl;
					if(!dek.Empty())
					{
						s=dek.Pop_Left();
						cout<<"� ���� ���������->\n"<<s;
					}else{
						cout<<"��� �������!\n";
					}
					system("pause");
					goto label1;
				}
			case'4':
				{
					system("cls");
					cout<<"\t�����Ӫ�� �� ���� ������\n"<<endl;
					if(!dek.Empty())
					{
						s=dek.Pop_Right();
						cout<<"� ���� ���������->\n"<<s;
					}else{
						cout<<"��� �������!\n";
					}
					system("pause");
					goto label1;
				}
			case'5':
				{
					system("cls");
					cout<<"\t���������� ���̲��\n"<<endl;
					cout<<"����� ����="<<dek.Size()<<endl;
					system("pause");
					goto label1;
				}
			case'6':
				{
					system("cls");
					cout<<"\t�������� ����\n"<<endl;
					dek.List();
					system("pause");
					goto label1;
				}
			case'7':
				{
					system("cls");
					cout<<"\t�������� ����\n"<<endl;
					dek.Clear();
					system("pause");
					goto label1;
				}
			case'8':
				{
					system("cls");
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
