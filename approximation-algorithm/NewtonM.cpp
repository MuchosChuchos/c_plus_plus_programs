#include<iostream>
#include<Windows.h>
#include<cmath>
#include<iomanip>

using namespace std;

double f(double x)
{
	return pow(x,3)-3*pow(x,2)+9*x-8;
}
double f1(double x)
{
	return 3*pow(x,2)-6*x+9;
}
double f2(double x)
{
	return 6*x-6;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	double e=0.001,a=-2,b=2,x,x1;
	cout<<"ÌÅÒÎÄ ÍÜÞÒÎÍÀ(äîòè÷íèõ)"<<endl<<endl;
	cout<<"Ð³âíÿííÿ: x^3-3x^2+9x-8=0"<<endl<<"Íà ïðîì³æêó: ["<<a<<";"<<b<<"]";
	cout<<endl<<"Òî÷í³ñòü: "<<e<<endl;
	cout<<setw(4)<<"x"<<setw(12)<<"f'(x)"<<setw(12)<<"f(x)"<<endl;
	/*
	* y = x^3-3x^2+9x-8
	* y' = 3x^2-6x+9
	* y'' = 6x-6
	*/
	if(f1(x)>0&&f2(x)>0) x1=a;
	else 				 x1=b;
	do
	{
		x=x1;
		x1=x-f(x)/f1(x);
		cout<<setprecision(5)<<x<<"\t"<<setw(10)<<setprecision(5)<<f1(x)<<"\t"<<setw(4)<<setprecision(5)<<f(x)<<endl;
	}while(abs(x-x1)>e);
	cout<<"\nÂ³äïîâ³äü:"<<endl;
	cout<<"\t    x="<<setprecision(5)<<x1;
	return 0;
}
