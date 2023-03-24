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
	cout<<"Ââåä³òü ðîçì³ð äåêà?->";
	cin>>n;
	Deq dek(n);
	data s;
	label1:
		system("cls");
		cout<<"0-Ñêîï³þâàòè äåêó"<<endl;
		cout<<"1-Çàøòîâõíóòè â äåêó çë³âà"<<endl<<"2-Çàøòîâõíóòè â äåêó ñïðàâà"<<endl;
		cout<<"3-Âèòÿãíóòè ³ç äåêà çë³â"<<endl<<"4-Âèòÿãíóòè ³ç äåêà ñïðàâà"<<endl;
		cout<<"5-Âèçíà÷èòè ðîçì³ð"<<endl<<"6-Ïåðåãëÿíóòè âì³ñò"<<endl;
		cout<<"7-Î÷èñòèòè äåêó"<<endl<<"8-Ïðî ïðîãðàìó"<<endl;
		cout<<"9-Âèõ³ä"<<endl<<endl<<"ÇÐÎÁ²ÒÜ ÂÈÁ²Ð->";
		punkt=getche();
		switch(punkt)
		{
			case'0':
				{
					system("cls");
					cout<<"\tÊÎÍÑÒÐÓÊÒÎÐ ÊÎÏ²ÞÂÀÍÍß\n"<<endl;
					Deq dek1(dek);
					cout<<"îðèã³íàë"<<endl;
					dek.List();
					cout<<"êîï³ÿ"<<endl;
					dek1.List();                                       
					system("pause");
					goto label1;
				}
			case'1':
				{
					system("cls");
					cout<<"\tÇÀØÒÎÂÕÓªÌÎ Â ÄÅÊÓ ÇË²ÂÀ\n"<<endl;
					cout<<"Ââåä³òü çíà÷åííÿ åëåìåíòà?->";
					s=getche();
					dek.Push_Left(s);
					cout<<endl;
					system("pause");
					goto label1;
				}
			case'2':
				{
					system("cls");
					cout<<"\tÇÀØÒÎÂÕÓªÌÎ Â ÄÅÊÓ ÑÏÐÀÂÀ\n"<<endl;
					cout<<"Ââåä³òü çíà÷åííÿ åëåìåíòà?->";
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
					cout<<"\tÂÈÒßÃÓªÌÎ ²Ç ÄÅÊÀ ÇË²ÂÀ\n"<<endl;
					if(!dek.Empty())
					{
						s=dek.Pop_Left();
						cout<<"Ç äåêè âèòÿãíóòî->\n"<<s;
					}else{
						cout<<"Äåê ïîðîæí³é!\n";
					}
					system("pause");
					goto label1;
				}
			case'4':
				{
					system("cls");
					cout<<"\tÂÈÒßÃÓªÌÎ ²Ç ÄÅÊÀ ÑÏÐÀÂÀ\n"<<endl;
					if(!dek.Empty())
					{
						s=dek.Pop_Right();
						cout<<"Ç äåêè âèòÿãíóòî->\n"<<s;
					}else{
						cout<<"Äåê ïîðîæí³é!\n";
					}
					system("pause");
					goto label1;
				}
			case'5':
				{
					system("cls");
					cout<<"\tÂÈÇÍÀ×ÅÍÍß ÐÎÇÌ²ÐÓ\n"<<endl;
					cout<<"Ðîçì³ð äåêà="<<dek.Size()<<endl;
					system("pause");
					goto label1;
				}
			case'6':
				{
					system("cls");
					cout<<"\tÏÅÐÅÃËßÄ ÄÅÊÀ\n"<<endl;
					dek.List();
					system("pause");
					goto label1;
				}
			case'7':
				{
					system("cls");
					cout<<"\tÎ×ÈÙÅÍÍß ÄÅÊÀ\n"<<endl;
					dek.Clear();
					system("pause");
					goto label1;
				}
			case'8':
				{
					system("cls");
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
