#include<iostream>
#include<conio.h>
#include<Windows.h>
#include "SStack.h"
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	char punkt;
	int n;
	cout<<"Ââåä³òü ðîçì³ð ñòåêà?->";
	cin>>n;
	SStack lifo(n);
	data s;
	label1:
		system("cls");
		cout<<"0-Ñêîï³þâàòè ñòåê"<<endl;
		cout<<"1-Çàøòîâõíóòè â ñòåê"<<endl<<"2-Âèòÿãíóòè ³ç ñòåêà"<<endl;
		cout<<"3-Âèçíà÷èòè ðîçì³ð"<<endl<<"4-Ïåðåãëÿíóòè âì³ñò"<<endl;
		cout<<"5-Î÷èñòèòè ñòåê"<<endl<<"6-Ïðî ïðîãðàìó"<<endl;
		cout<<"7-Âèõ³ä"<<endl<<endl<<"ÇÐÎÁ²ÒÜ ÂÈÁ²Ð->";
		punkt=getche();
		switch(punkt)
		{
			case'0':
				{
					system("cls");
					cout<<"\tÊÎÍÑÒÐÓÊÒÎÐ ÊÎÏ²ÞÂÀÍÍß\n"<<endl;
					SStack lifo1(lifo);
					cout<<"îðèã³íàë"<<endl;
					lifo.List();
					cout<<"êîï³ÿ"<<endl;
					lifo1.List();
					system("pause");
					goto label1;
				}
			case'1':
				{
					system("cls");
					cout<<"\tÇÀØÒÎÂÕÓªÌÎ Â ÑÒÅÊ\n"<<endl;
					cout<<"Ââåä³òü çíà÷åííÿ åëåìåíòà?->";
					s=getche();
					lifo.Push(s);
					cout<<endl;
					system("pause");
					goto label1;
				}
			case'2':
				{
					system("cls");
					cout<<"\tÂÈÒßÃÓªÌÎ ²Ç ÑÒÅÊÀ\n"<<endl;
					if(!lifo.Empty())
					{
						s=lifo.Pop();
						cout<<"Ç ñòåêà âèòÿãíóòî->\n"<<s;
					}else{
						cout<<"Ñòåê ïîðîæí³é!\n";
					}
					system("pause");
					goto label1;
				}
			case'3':
				{
					system("cls");
					cout<<"\tÂÈÇÍÀ×ÅÍÍß ÐÎÇÌ²ÐÓ\n"<<endl;
					cout<<"Ðîçì³ð ñòåêà="<<lifo.Size()<<endl;
					system("pause");
					goto label1;
				}
			case'4':
				{
					system("cls");
					cout<<"\tÏÅÐÅÃËßÄ ÑÒÅÊÀ\n"<<endl;
					lifo.List();
					system("pause");
					goto label1;
				}
			case'5':
				{
					system("cls");
					cout<<"\tÎ×ÈÙÅÍÍß ÑÒÅÊÀ\n"<<endl;
					lifo.Clear();
					system("pause");
					goto label1;
				}
			case'6':
				{
					system("cls");
					cout<<"ÏÐÎ ÏÐÎÃÐÀÌÓ"<<endl;
					system("pause");
					goto label1;
				}
			case'7':
				{
					system("cls");
					lifo.~SStack();
					cout<<endl<<"Ðîáîòà ïðîãðàìè çàâåðøåíà!"<<endl<<"Ñòåê âèäàëåíî!"<<endl;
					system("pause");
					return 0;
				}
			default:
				{
					cout<<endl<<"ÍÅÏÐÀÂÈËÜÍÈÉ ÂÈÁ²Ð"<<endl;
					system("pause");
					goto label1;
				}
		}
}
