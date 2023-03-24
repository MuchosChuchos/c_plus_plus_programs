#include "Queue.h"
#include <iostream>
#include<iomanip>
using namespace std;
Queue::Queue(unsigned int n):Max_size(n+1)
{
	queue=new data[Max_size];
	top=0;
	bottom=0;
}
Queue::Queue(const Queue &st):Max_size(st.Max_size)
{
	queue=new data[Max_size];
	int i=top;
	top=st.top;
	bottom=st.bottom;
	while(i!=bottom)
	{
		queue[i]=st.queue[i];
		i=(i+1)%Max_size;
	}
}
void Queue::Clear()
{
	top=bottom;
}
int Queue::Size()
{
	if (bottom>=top)
		return bottom-top;
	else
		return bottom+Max_size-top;
}
bool Queue::Empty()
{
	return (top==bottom)?true:false;
}
bool Queue::Full()
{
	return ((bottom+1)%Max_size==top)?true:false;
}
void Queue::Push(data d)
{
	if(!Full())
	{
		queue[bottom]=d;
		bottom=(bottom+1)%Max_size;
	}
	else
		cout<<"Queue is full"<<endl;
}
data Queue::Pop()
{
	data temp;
	if(!Empty())
		temp=queue[top];
	top=(top+1)%Max_size;
	return temp;
}
void Queue::List()
{
	int i=top;
	if(!Empty())
	{
		cout<<"DATA in the queue:\n";
		while(i!=bottom)
		{
			cout<<setw(3)<<queue[i];
			i=(i+1)%Max_size;
		}
		cout<<endl;
	}
	else
	{
		cout<<"Queue is empty"<<endl;
	}
}
Queue::~Queue()
{
	delete[]queue;
}
