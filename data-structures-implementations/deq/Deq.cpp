#include "Deq.h"
#include<iostream>
#include<iomanip>
using namespace std;

Deq::Deq(Deq &dq):Max_size(dq.Max_size)
{
	for(int i=left;i!=right;(i+1)%Max_size)
		deq[i]=dq.deq[i];
}

Deq::Deq(unsigned int n):Max_size(n+2)
{
	deq=new data[Max_size];
	left=0;right=1;
	size=0;
}

void Deq::Clear()
{
	left=0;right=1;
	size=0;
}

int Deq::Size()
{
	return size;
}

void Deq::List()
{
	int i=(left+1)%Max_size;
	if(!Empty())
	{
		cout<<"Дані дека:\n";
		while(i!=right)
		{
			cout<<setw(3)<<deq[i];
			i=(i+1)%Max_size;
		}
		cout<<"\n";
	}
	else 
		cout<<"Дек порожній!\n";
}

bool Deq::Full()
{
	return size==Max_size-2?true:false;
}

bool Deq::Empty()
{
	return size==0?true:false;
}

data Deq::Pop_Left()
{
	if(!Empty())
	{
		left=(left+1)%Max_size;
		size--;
		return deq[left];
	}
}

data Deq::Pop_Right()
{
	if(!Empty())
	{
		if(right!=0)
			right--;
		else 
			right=Max_size-1;
		size--;
		return deq[right];
	}
}

void Deq::Push_Left(data c)
{
	if(!Full())
	{
		deq[left]=c;
		size++;
		if (left!=0)
			left--;
		else
			left=Max_size-1;
	}
	else
		cout<<"Дек заповнений!\n";
}

void Deq::Push_Right(data c)
{
	if(!Full())
	{
		deq[right]=c;
		size++;
		right=(right+1)%Max_size;
	}
	else
		cout<<"Дек заповнений!\n";
}

Deq::~Deq()
{
	delete[] deq;
}
