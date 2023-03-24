#include<iostream>
#include <conio.h>
#include<ctype.h>
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include<fstream>
#include<windows.h>
using namespace std;

int* Init_auto(const int, int, int);
int* Init_arr(const int);
void Read_file();
void Print_arr(const int, const int*);
void Save_file(const int, int*);
void List_help();
int* Copy_mas(const int,int*);
void Sort_Vibor(const int, int*);
void Sort_Heap(const int, int*);

int size, O_vibor, O_heap;
clock_t t,t1;
int *mas;
int *mas_after;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	///////////////////////////////////////////////////////////////////////////////////
	HWND hwnd;       
    char Title[1024];
    GetConsoleTitle(Title, 1024); 
    hwnd=FindWindow(NULL, Title); 
    MoveWindow(hwnd,200,200,900,500,TRUE);
    cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t   ���������� ����²�"<<"\n\t\t\t\t\t   ";
    Sleep(1000);
    for(int i=0;i<9;i++)
	{
		cout<<"__";
		Sleep(200);
	}
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t��������� ����-��� ������";
	_getch();
	for(int i=0;i<3;i++)
	{
		cout<<".";
		Sleep(350);
	}
	///////////////////////////////////////////////////////////////////////////////////
	
	char ch;
	label1:
		system("cls");
		cout<<"1-���������� ������ � �����"<<endl<<"2-����������� ������ ������"<<endl;
		cout<<"3-����������� ������ ��������"<<endl<<"4-���������� �������"<<endl;
		cout<<"5-ϳ��������� ����������"<<endl<<"6-��������� �� �����"<<endl;
		cout<<"7-����� � ����"<<endl<<"8-��� ��������"<<endl;
		cout<<"9-�����"<<endl<<endl<<"������� �����->";
		ch=getche();
		switch(ch)
		{
			case'1':
				{
					system("cls");
					cout<<"......���������� � �����......"<<endl;
					for(int i=0;i<15;i++)
					{
						cout<<"__";
						Sleep(100);
					}
					cout<<endl<<endl;
					//////////////////
					
					Read_file();
					cout<<"����� �������!"<<endl;
					
					//////////////////
					system("pause");
					goto label1;	
				}
			case'2':
				{
					size:
					system("cls");
					cout<<"......�Ͳֲ�˲��ֲ� ������......"<<endl;
					for(int i=0;i<16;i++)
					{
						cout<<"__";
						Sleep(100);
					}
					cout<<endl<<endl;
					//////////////////
					
					cout<<"������ ��������� ������?->";cin>>size;
					cin.ignore(32767,'\n');
					if (cin.fail()) 
					{
					    cin.clear();
					    cin.ignore(32767,'\n');
					}
					if(size<=0)
					{
						cout<<"����������� ��� �����!!!"<<endl;
						cout<<"��������� �� ���!";
						Sleep(4500);
						goto size;
					}else if(size>1000000)
					{
						cout<<"������� ������ ��������� ������!!"<<endl;
						cout<<"��������� �� ���!";
						Sleep(5000);
						goto size;
					}
					mas = Init_arr(size);
					cout<<"����� ��������� "<<size<<" ��������"<<endl;
					
					//////////////////
					system("pause");
					goto label1;	
				}
			case'3':
				{
					size2:
					system("cls");
					cout<<"......�Ͳֲ�˲��ֲ� ��������......"<<endl;
					for(int i=0;i<17;i++)
					{
						cout<<"__";
						Sleep(100);
					}
					cout<<endl<<endl;
					//////////////////
					
					int l, r;
					cout<<"������ ��������� ������?->";cin>>size;
					cin.ignore(32767,'\n');
					if (cin.fail()) 
					{
					    cin.clear();
					    cin.ignore(32767,'\n');
					}
					if(size<=0)
					{
						cout<<"����������� ��� �����!!!"<<endl;
						cout<<"��������� �� ���!";
						Sleep(4500);
						size=0;
						goto size2;
					}else if(size>1000000)
					{
						cout<<"������� ������ ��������� ������!!"<<endl;
						cout<<"��������� �� ���!";
						Sleep(5000);
						goto size2;
					}
					cout<<"������ ��� ����?->";//scanf("%d", &l);
					if(scanf("%d", &l)!=1)
					{
						cout<<"����������� ��� �����!!!"<<endl;
						cout<<"��������� �� ���!";
						fflush(stdin);
						Sleep(4500);
						goto size2;
					}else scanf("%*[^\n]");
					if(l<-37650||l>37650)
					{
						cout<<"˳�� ���� ������� ���� � ������� \"-37650 .. 37650\""<<endl;
						cout<<"��������� �� ���!";
						Sleep(5000);
						goto size2;
					}
					cout<<"������ ����� ����?->";//scanf("%d", &r);
					if(scanf("%d", &r)!=1)
					{
						cout<<"����������� ��� �����!!!"<<endl;
						cout<<"��������� �� ���!";
						fflush(stdin);
						Sleep(4500);
						goto size2;
					}else scanf("%*[^\n]");
					if(r<-37650||r>37650)
					{
						cout<<"����� ���� ������� ���� � ������� \"-37650 .. 37650\""<<endl;
						cout<<"��������� �� ���";
						Sleep(5000);
						goto size2;
					}
					if(l>r)
					{
						cout<<"˳�� ���� �� ������� ������������ �������� ����� ���!!!"<<endl;
						cout<<"��������� �� ���!";
						Sleep(5000);
						goto size2;
					}
					mas = Init_auto(size, l, r);
					cout<<"����� ��������� "<<size<<" ��������"<<endl;
					
					//////////////////
					system("pause");
					goto label1;
				}
			case'4':
				{
					system("cls");
					cout<<"......���������� �������......"<<endl;
					for(int i=0;i<15;i++)
					{
						cout<<"__";
						Sleep(100);
					}
					cout<<endl<<endl;
					//////////////////
					
					mas_after = Copy_mas(size,mas);
					t=clock();
					Sort_Vibor(size, mas_after);
					t=clock() - t;
					cout<<"����� �����������!"<<endl;
					
					//////////////////
					system("pause");
					goto label1;
				}
			case'5':
				{
					system("cls");
					cout<<"......ϲ��̲������ ����������......"<<endl;
					for(int i=0;i<17;i++)
					{
						cout<<"__";
						Sleep(100);
					}
					cout<<endl<<endl;
					//////////////////
					
					mas_after = Copy_mas(size,mas);
					t1=clock();
					Sort_Heap(size, mas_after);
					t1=clock() - t1;
					cout<<"����� �����������!"<<endl;
					
					//////////////////
					system("pause");
					goto label1;
				}
			case'6':
				{
					system("cls");
					cout<<"......�������� ������......"<<endl;
					for(int i=0;i<13;i++)
					{
						cout<<"__";
						Sleep(100);
					}
					cout<<endl<<endl;
					//////////////////
					
					if(mas_after&&mas)
					{
						cout<<"����� �� ����������:"<<endl;
						Print_arr(size, mas);
						cout<<"\n����� ���� ����������:"<<endl;
						Print_arr(size, mas_after);
						cout<<endl;
						if((double)t!=0)
							cout<<"��� ���������� ������ ������� ������� ������: "<<((double)t)/CLOCKS_PER_SEC<<" s"<<endl;
						if((double)t1!=0)
							cout<<"��� ���������� ������ ����������� �������: "<<((double)t1)/CLOCKS_PER_SEC<<" s"<<endl;
						if(O_vibor!=0)
							cout<<"ʳ������ ������������, ��������� �� ��� ���������� ������ ������� ������� ������: "<<O_vibor<<endl;
						if(O_heap!=0)
							cout<<"ʳ������ ������������, ��������� �� ��� ���������� ������ ����������� �������: "<<O_heap<<endl;
					}else 
					{
						Print_arr(size, mas);
						cout<<endl;
					}
					if(!mas)
					{
						cout<<"��� ������� ������� �������� �����!\n";
					}
					
					//////////////////
					system("pause");
					goto label1;
				}
			case'7':
				{
					system("cls");
					cout<<"......����� � ����......"<<endl;
					for(int i=0;i<12;i++)
					{
						cout<<"__";
						Sleep(100);
					}
					cout<<endl<<endl;
					//////////////////
					
					if(mas)
					{
						Save_file(size,mas_after);
						cout<<"��������� � ���� result.txt"<<endl;
					}else{
						cout<<"ͳ���� �� ���������!!"<<endl;
						cout<<"���� �����, ������� �������� ����� �� ���������� ���� ��� ���������� ���������� ���������� � ����!!!"<<endl;	
					}
					
					//////////////////
					system("pause");
					goto label1;
				}
			case'8':
				{
					system("cls");
					cout<<"......��� ��������......"<<endl;
					for(int i=0;i<12;i++)
					{
						cout<<"__";
						Sleep(100);
					}
					cout<<endl<<endl;
					//////////////////
					
					List_help();
					
					//////////////////
					system("pause");
					goto label1;
				}
			case'9':
				{
					system("cls");
					cout<<endl<<"������ �������� ���������!"<<endl<<endl;
					delete mas;
					delete mas_after;
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
int* Init_arr(int n)
{
	delete mas;
	int *arr=new int[n];
	for (int i = 0; i < n; i++)
	{
		initmas:
		cout<<"������ "<<i+1<<" �������?->";//cin>>*(arr + i);
		if(scanf("%d", &*(arr + i))!=1)
		{
			cout<<"����������� ��� �����!!!"<<endl;
			cout<<"��������� �� ���!\n";
			fflush(stdin);
			Sleep(4500);
			goto initmas;
		}else scanf("%*[^\n]");
		if(*(arr + i)<-37650||*(arr + i)>37650)
		{
			cout<<"������� ������ ������� ���� � ������� \"-37650 .. 37650\""<<endl;
			cout<<"��������� �� ���!\n";
			Sleep(5000);
			goto initmas;
		}
	}
	return arr;
}
int* Init_auto(int n, int l, int r)
{
	delete mas;
	int *arr=new int[n];
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
		*(arr + i) = l + rand() % (r - l + 1);
	return arr;
}
void Read_file()
{
	delete mas;
	cout<<"������ ��'� ����� ?-> ";
	char s[30];
	cin>>s;
	ifstream f2(s,ios::in);
					if(!f2.is_open())
					{
						printf("���� ������� �� �������\n");
						system("pause");
						exit(0);
					}
					f2>>size;
					mas=new int[size];
					
						for (int i = 0; i < size; i++)
							f2>>mas[i];
	f2.close();
}
void Print_arr(const int n, const int* arr)
{
	for (int i = 0; i < n; i++)
		printf("%-6d", *(arr + i));
}
void Save_file(const int n, int*a)
{
	ofstream f("result.txt",ios::out);
	for (int i = 0; i < n; i++)
		f<<a[i]<<" ";
	f<<endl;
	if((double)t!=0)
		f<<"��� ���������� ������ ������� ������� ������: "<<((double)t)/CLOCKS_PER_SEC<<" s"<<endl;
	if((double)t1!=0)
		f<<"��� ���������� ������ ����������� �������: "<<((double)t1)/CLOCKS_PER_SEC<<" s"<<endl;
	if(O_vibor!=0)
		f<<"ʳ������ ������������, ��������� �� ��� ���������� ������ ������� ������� ������: "<<O_vibor<<endl;
	if(O_heap!=0)
		f<<"ʳ������ ������������, ��������� �� ��� ���������� ������ ����������� �������: "<<O_heap<<endl;
	f.close();
}
void List_help()
{
	cout<<"��� �������� ������ �������� ��������� ������� ������� �������� �����:"<<endl;
	cout<<" - �������� ����� ����� �� 3 �������������� �������: ������� �� �����(�. \"1\"), ������(�. \"2\"), ��������(�. \"3\"));"<<endl;
	cout<<" - ³���������� ����� ����� ��������: ������� ������ (�. \"4\") �� ����������� ������� (�. \"5\");"<<endl;
	cout<<"ϳ��� ��������� ��� ����� �� ������ ����������� ��������� ������ ��������(�. \"6\") ���"<<endl;
	cout<<"�������� ���������� �� ����� result.txt(�. \"7\").";
	cout<<endl<<endl;
	Sleep(12000);
	cout<<"�������� ������ �������� ������� ����� �-320 �������� �������"<<endl;
	cout<<"����� ������ ������� ��� ������ ���������� ������ �� ����� ���������� �� �� ������� ������������,"<<endl;
	cout<<"��� ����������� ������� � ��� ������ ����� ���..."<<endl<<endl;
}
int* Copy_mas(const int s, int*a)
{
	int *new_arr = new int[s];
	for(int i=0;i<s;i++)
		new_arr[i]=a[i];
	return new_arr;
}
void Sort_Vibor(const int N, int*a)
{
	int min = 0;
	int buf = 0; 
	O_vibor=0;
	for (int i = 0; i < N; i++)
	{
		min = i;
		for (int j = i + 1; j < N; j++)
			min = ( a[j] < a[min] ) ? j : min;
		if (i != min)
		{
			buf = a[i];
			a[i] = a[min];
			a[min] = buf;
			O_vibor++;
		}
	}
}
void swap (int &n1, int &n2) 
{
	O_heap++;
    int temp = n1;
    n1 = n2;
    n2 = temp;
}
void Sort_Heap(const int n, int*a)
{
	O_heap=0;
	int sh = 0;
    bool b;
    do 
    {
	    b = false;
	    for (int i = 0; i < n; i++) 
        {
	        if (i * 2 + 2 + sh < n) 
            {
		        if ((a[i + sh] > /*<*/ a[i * 2 + 1 + sh]) || (a[i + sh] > /*<*/ a[i * 2 + 2 + sh])) 
                {
		            if (a[i * 2 + 1 + sh] < /*>*/ a[i * 2 + 2 + sh]) 
                    {
			            swap(a[i + sh], a[i * 2 + 1 + sh]);
			            b = true;
		            } 
                    else if (a[i * 2 + 2 + sh] < /*>*/ a[i * 2 + 1 + sh]) 
                    {
		                swap(a[i + sh], a[i * 2 + 2 + sh]);
		                b = true;
		            }
		        }
		        if (a[i * 2 + 2 + sh] < /*>*/ a[i * 2 + 1 + sh]) 
                {
			        swap(a[i * 2 + 1 + sh], a[i * 2 + 2 + sh]);
                    b = true;
			    }
	        }
            else if (i * 2 + 1 + sh < n) 
            {
	            if (a[i + sh] > /*<*/ a[ i * 2 + 1 + sh]) 
                {
	                swap(a[i + sh], a[i * 2 + 1 + sh]);
	                b = true;
	            }
	        }
	    }
	    if (!b)
            ++sh;
    } while (sh + 2 < n);
}
