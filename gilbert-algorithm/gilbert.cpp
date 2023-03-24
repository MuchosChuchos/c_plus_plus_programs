#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<iostream>
#include<windows.h>
using namespace std;
const int 	del = 100;
int h;

void GD(int); void GU(int);
int round(float a)
{return (int)floor(a+0.5);}

void LineDown() {linerel(0,h);}
void LineUp() {linerel(0,-h);}
void LineLeft() {linerel(-h,0);}
void LineRight() {linerel(h,0);}
void GL(int i)
{
	if (i>0)
		{
			GD(i-1); LineLeft();
			GL(i-1); LineDown();
			GL(i-1); LineRight();
			GU(i-1); delay(del);
		}
}

void GR(int i)
{
	if (i>0)
		{
			GU(i-1); LineRight();
			GR(i-1); LineUp();
			GR(i-1); LineLeft();
			GD(i-1); delay(del);
		}
}

void GU(int i)
{
	if (i>0)
		{
			GR(i-1); LineUp();
			GU(i-1); LineRight();
			GU(i-1); LineDown();
			GL(i-1); delay(del);
		}
}

void GD(int i)
{
	if (i>0)
		{
			GL(i-1); LineDown();
			GD(i-1); LineLeft();
			GD(i-1); LineUp();
			GR(i-1); delay(del);
		}
}

int main()
{
	int n,orient,x0,y0,S,Hscr,Wscr;
	float PrS;
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	do
	{
		cout<<"Довжина сторони опорного квадрата в \% від висоти екрана?->";
		cin>>PrS;
	}while(PrS>=100);
	cout<<"\nВведіть порядок кривої: "; cin>>n;
	do
	{
		cout<<"\nВведіть орієнтацію кривої: ";
		cout<<"вверх - 1, вниз - 2, вправо - 3, вліво - 4  ?->";cin>>orient;
	}while(orient<1 || orient>4);
	initwindow(1920,1080);
	Hscr=getmaxy()+1;//Висота екрана
	Wscr=getmaxx()+1;//Ширина екрана
	S=round(PrS/100*Hscr);
	h=round(S/(pow(2,n)-1));
	if(orient == 1 || orient == 3)
		{x0=Wscr/2 - S/2; y0=Hscr/2 + S/2;}
	else {x0=Wscr/2 + S/2; y0=Hscr/2 - S/2;}
	
	moveto(x0, y0);
	
	switch(orient)
	{
		case 1: GU(n); break;
		case 2: GD(n); break;
		case 3: GR(n); break;
		case 4: GL(n); break;
	}
	getche();
	closegraph();
	return 0;
}
