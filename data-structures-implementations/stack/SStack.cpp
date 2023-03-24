#include "SStack.h"
#include <iostream>
#include<iomanip>
using namespace std;
SStack::SStack(unsigned int n):Max_size(n)
{
	stack=new data[Max_size];
	top=-1;
}
SStack::SStack(const SStack &st):Max_size(st.Max_size)
{
	stack=new data[Max_size];
	top=st.top;
	for(int i=0;i<=top;i++)
		stack[i]=st.stack[i];
}
void SStack::Clear()
{
	top=-1;
}
int SStack::Size()
{
	return top+1;
}
bool SStack::Empty()
{
	return (top==-1)?true:false;
}
bool SStack::Full()
{
	return (top==Max_size-1)?true:false;
}
void SStack::Push(data c)
{
	if(!Full())
		stack[++top]=c;
	else
		cout<<"Stack is full"<<endl;
}
data SStack::Pop()
{
	if(!Empty())
		return stack[top--];
}
void SStack::List()
{
	if(!Empty())
	{
		cout<<"DATA in the stack:\n";
		for(int i=top;i>-1;i--)
		cout<<setw(3)<<stack[i];
		cout<<endl;
	}
	else
	{
		cout<<"Stack is empty"<<endl;
	}
}
SStack::~SStack()
{
	delete[]stack;
}
