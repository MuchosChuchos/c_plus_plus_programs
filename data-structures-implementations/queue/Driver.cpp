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
	cout<<"Ââåä³òü ðîçì³ð ÷åðãè?->";
	cin>>n;
	Queue fifo(n);
	data s;
	label1:
		system("cls");
		cout<<"0-Ñêîï³þâàòè ÷åðãó"<<endl;
		cout<<"1-Çàøòîâõíóòè â ÷åðãó"<<endl<<"2-Âèòÿãíóòè ³ç ÷åðãè"<<endl;
		cout<<"3-Âèçíà÷èòè ðîçì³ð"<<endl<<"4-Ïåðåãëÿíóòè âì³ñò"<<endl;
		cout<<"5-Î÷èñòèòè ÷åðãó"<<endl<<"6-Ïðî ïðîãðàìó"<<endl;
		cout<<"7-Âèõ³ä"<<endl<<endl<<"ÇÐÎÁ²ÒÜ ÂÈÁ²Ð->";
		punkt=getche();
		switch(punkt)
		{
			case'0':
				{
					system("cls");
					cout<<"\tÊÎÍÑÒÐÓÊÒÎÐ ÊÎÏ²ÞÂÀÍÍß\n"<<endl;
					Queue fifo1(fifo);
					cout<<"îðèã³íàë"<<endl;
					fifo.List();
					cout<<"êîï³ÿ"<<endl;
					fifo1.List();
					system("pause");
					goto label1;
				}
			case'1':
				{
					system("cls");
					cout<<"\tÇÀØÒÎÂÕÓªÌÎ Â ×ÅÐÃÓ\n"<<endl;
					cout<<"Ââåä³òü çíà÷åííÿ åëåìåíòà?->";
					s=getche();
					fifo.Push(s);
					cout<<endl;
					system("pause");
					goto label1;
				}
			case'2':
				{
					system("cls");
					cout<<"\tÂÈÒßÃÓªÌÎ ²Ç ×ÅÐÃÈ\n"<<endl;
					if(!fifo.Empty())
					{
						s=fifo.Pop();
						cout<<"Ç ÷åðãè âèòÿãíóòî->\n"<<s;
					}else{
						cout<<"×åðãà ïîðîæíÿ!\n";
					}
					system("pause");
					goto label1;
				}
			case'3':
				{
					system("cls");
					cout<<"\tÂÈÇÍÀ×ÅÍÍß ÐÎÇÌ²ÐÓ\n"<<endl;
					cout<<"Ðîçì³ð ÷åðãè="<<fifo.Size()<<endl;
					system("pause");
					goto label1;
				}
			case'4':
				{
					system("cls");
					cout<<"\tÏÅÐÅÃËßÄ ×ÅÐÃÈ\n"<<endl;
					fifo.List();
					system("pause");
					goto label1;
				}
			case'5':
				{
					system("cls");
					cout<<"\tÎ×ÈÙÅÍÍß ×ÅÐÃÈ\n"<<endl;
					fifo.Clear();
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
					fifo.~Queue();
					cout<<endl<<"Ðîáîòà ïðîãðàìè çàâåðøåíà!"<<endl<<"×åðãó âèäàëåíî!"<<endl;
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
