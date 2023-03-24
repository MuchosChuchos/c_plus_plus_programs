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
    cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t   СОРТУВАННЯ МАСИВІВ"<<"\n\t\t\t\t\t   ";
    Sleep(1000);
    for(int i=0;i<9;i++)
	{
		cout<<"__";
		Sleep(200);
	}
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tнатисність будь-яку кнопку";
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
		cout<<"1-Зчитування масиву з файлу"<<endl<<"2-Ініціалізація масиву вручну"<<endl;
		cout<<"3-Ініціалізація масиву рандомно"<<endl<<"4-Сортування вибором"<<endl;
		cout<<"5-Пірамідальне сортування"<<endl<<"6-Виведення на екран"<<endl;
		cout<<"7-Запис в файл"<<endl<<"8-Про програму"<<endl;
		cout<<"9-Вихід"<<endl<<endl<<"ЗРОБІТЬ ВИБІР->";
		ch=getche();
		switch(ch)
		{
			case'1':
				{
					system("cls");
					cout<<"......ЗЧИТУВАННЯ З ФАЙЛУ......"<<endl;
					for(int i=0;i<15;i++)
					{
						cout<<"__";
						Sleep(100);
					}
					cout<<endl<<endl;
					//////////////////
					
					Read_file();
					cout<<"Масив зчитано!"<<endl;
					
					//////////////////
					system("pause");
					goto label1;	
				}
			case'2':
				{
					size:
					system("cls");
					cout<<"......ІНІЦІАЛІЗАЦІЯ ВРУЧНУ......"<<endl;
					for(int i=0;i<16;i++)
					{
						cout<<"__";
						Sleep(100);
					}
					cout<<endl<<endl;
					//////////////////
					
					cout<<"Введіть розмірність масиву?->";cin>>size;
					cin.ignore(32767,'\n');
					if (cin.fail()) 
					{
					    cin.clear();
					    cin.ignore(32767,'\n');
					}
					if(size<=0)
					{
						cout<<"Некоректний ввід даних!!!"<<endl;
						cout<<"Спробуйте ще раз!";
						Sleep(4500);
						goto size;
					}else if(size>1000000)
					{
						cout<<"Занадто велика розмірність масиву!!"<<endl;
						cout<<"Спробуйте ще раз!";
						Sleep(5000);
						goto size;
					}
					mas = Init_arr(size);
					cout<<"Масив розмірністю "<<size<<" створено"<<endl;
					
					//////////////////
					system("pause");
					goto label1;	
				}
			case'3':
				{
					size2:
					system("cls");
					cout<<"......ІНІЦІАЛІЗАЦІЯ РАНДОМНО......"<<endl;
					for(int i=0;i<17;i++)
					{
						cout<<"__";
						Sleep(100);
					}
					cout<<endl<<endl;
					//////////////////
					
					int l, r;
					cout<<"Введіть розмірність масиву?->";cin>>size;
					cin.ignore(32767,'\n');
					if (cin.fail()) 
					{
					    cin.clear();
					    cin.ignore(32767,'\n');
					}
					if(size<=0)
					{
						cout<<"Некоректний ввід даних!!!"<<endl;
						cout<<"Спробуйте ще раз!";
						Sleep(4500);
						size=0;
						goto size2;
					}else if(size>1000000)
					{
						cout<<"Занадто велика розмірність масиву!!"<<endl;
						cout<<"Спробуйте ще раз!";
						Sleep(5000);
						goto size2;
					}
					cout<<"Введіть ліву межу?->";//scanf("%d", &l);
					if(scanf("%d", &l)!=1)
					{
						cout<<"Некоректний ввід даних!!!"<<endl;
						cout<<"Спробуйте ще раз!";
						fflush(stdin);
						Sleep(4500);
						goto size2;
					}else scanf("%*[^\n]");
					if(l<-37650||l>37650)
					{
						cout<<"Ліва межа повинна бути в діапазоні \"-37650 .. 37650\""<<endl;
						cout<<"Спробуйте ще раз!";
						Sleep(5000);
						goto size2;
					}
					cout<<"Введіть праву межу?->";//scanf("%d", &r);
					if(scanf("%d", &r)!=1)
					{
						cout<<"Некоректний ввід даних!!!"<<endl;
						cout<<"Спробуйте ще раз!";
						fflush(stdin);
						Sleep(4500);
						goto size2;
					}else scanf("%*[^\n]");
					if(r<-37650||r>37650)
					{
						cout<<"Права межа повинна бути в діапазоні \"-37650 .. 37650\""<<endl;
						cout<<"Спробуйте ще раз";
						Sleep(5000);
						goto size2;
					}
					if(l>r)
					{
						cout<<"Ліва межа не повинна перевищувати значення правої межі!!!"<<endl;
						cout<<"Спробуйте ще раз!";
						Sleep(5000);
						goto size2;
					}
					mas = Init_auto(size, l, r);
					cout<<"Масив розмірністю "<<size<<" створено"<<endl;
					
					//////////////////
					system("pause");
					goto label1;
				}
			case'4':
				{
					system("cls");
					cout<<"......СОРТУВАННЯ ВИБОРОМ......"<<endl;
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
					cout<<"Масив відсортовано!"<<endl;
					
					//////////////////
					system("pause");
					goto label1;
				}
			case'5':
				{
					system("cls");
					cout<<"......ПІРАМІДАЛЬНЕ СОРТУВАННЯ......"<<endl;
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
					cout<<"Масив відсортовано!"<<endl;
					
					//////////////////
					system("pause");
					goto label1;
				}
			case'6':
				{
					system("cls");
					cout<<"......ПЕРЕГЛЯД МАСИВУ......"<<endl;
					for(int i=0;i<13;i++)
					{
						cout<<"__";
						Sleep(100);
					}
					cout<<endl<<endl;
					//////////////////
					
					if(mas_after&&mas)
					{
						cout<<"Масив до сортування:"<<endl;
						Print_arr(size, mas);
						cout<<"\nМасив після сортування:"<<endl;
						Print_arr(size, mas_after);
						cout<<endl;
						if((double)t!=0)
							cout<<"Час сортування масиву методом прямого вибору: "<<((double)t)/CLOCKS_PER_SEC<<" s"<<endl;
						if((double)t1!=0)
							cout<<"Час сортування масиву пірамідальним методом: "<<((double)t1)/CLOCKS_PER_SEC<<" s"<<endl;
						if(O_vibor!=0)
							cout<<"Кількість перестановок, виконаних під час сортування масиву методом прямого вибору: "<<O_vibor<<endl;
						if(O_heap!=0)
							cout<<"Кількість перестановок, виконаних під час сортування масиву пірамідальним методом: "<<O_heap<<endl;
					}else 
					{
						Print_arr(size, mas);
						cout<<endl;
					}
					if(!mas)
					{
						cout<<"Для початку потрібно створити масив!\n";
					}
					
					//////////////////
					system("pause");
					goto label1;
				}
			case'7':
				{
					system("cls");
					cout<<"......ЗАПИС В ФАЙЛ......"<<endl;
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
						cout<<"Збережено у файл result.txt"<<endl;
					}else{
						cout<<"Нічого не збережено!!"<<endl;
						cout<<"Будь ласка, створіть спочатку масив та відсортуйте його для збереження результатів сортування у файл!!!"<<endl;	
					}
					
					//////////////////
					system("pause");
					goto label1;
				}
			case'8':
				{
					system("cls");
					cout<<"......ПРО ПРОГРАМУ......"<<endl;
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
					cout<<endl<<"Робота програми завершена!"<<endl<<endl;
					delete mas;
					delete mas_after;
					system("pause");
					return 0;
				}
			default:
				{
					cout<<endl<<"НЕПРАВИЛЬНИЙ ВИБІР"<<endl;
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
		cout<<"Введіть "<<i+1<<" елемент?->";//cin>>*(arr + i);
		if(scanf("%d", &*(arr + i))!=1)
		{
			cout<<"Некоректний ввід даних!!!"<<endl;
			cout<<"Спробуйте ще раз!\n";
			fflush(stdin);
			Sleep(4500);
			goto initmas;
		}else scanf("%*[^\n]");
		if(*(arr + i)<-37650||*(arr + i)>37650)
		{
			cout<<"Елемент масиву повинен бути в діапазоні \"-37650 .. 37650\""<<endl;
			cout<<"Спробуйте ще раз!\n";
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
	cout<<"Введіть ім'я файлу ?-> ";
	char s[30];
	cin>>s;
	ifstream f2(s,ios::in);
					if(!f2.is_open())
					{
						printf("Файл відкрити не вдалося\n");
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
		f<<"Час сортування масиву методом прямого вибору: "<<((double)t)/CLOCKS_PER_SEC<<" s"<<endl;
	if((double)t1!=0)
		f<<"Час сортування масиву пірамідальним методом: "<<((double)t1)/CLOCKS_PER_SEC<<" s"<<endl;
	if(O_vibor!=0)
		f<<"Кількість перестановок, виконаних під час сортування масиву методом прямого вибору: "<<O_vibor<<endl;
	if(O_heap!=0)
		f<<"Кількість перестановок, виконаних під час сортування масиву пірамідальним методом: "<<O_heap<<endl;
	f.close();
}
void List_help()
{
	cout<<"Для коректної роботи програми необхідно вводити коректні значення також:"<<endl;
	cout<<" - Створити масив одним із 3 запропонованих способів: готовий із файлу(п. \"1\"), вручну(п. \"2\"), рандомно(п. \"3\"));"<<endl;
	cout<<" - Відсортувати масив двома методами: прямого вибору (п. \"4\") та пірамідальним методом (п. \"5\");"<<endl;
	cout<<"Після виконання цих кроків Ви можете переглянути результат роботи програми(п. \"6\") або"<<endl;
	cout<<"зберегти результати до файлу result.txt(п. \"7\").";
	cout<<endl<<endl;
	Sleep(12000);
	cout<<"Курсовий проект розробив студент групи П-320 Артемчук Анатолій"<<endl;
	cout<<"Даний проект порівнює два методи сортування масивів за часом сортування та за кількістю перестановок,"<<endl;
	cout<<"про ефективність кожного з них судити тільки Вам..."<<endl<<endl;
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
