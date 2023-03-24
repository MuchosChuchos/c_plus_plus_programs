#ifndef SSTACK_H
#define SSTACK_H

typedef char data;

class SStack
{
	private:
		unsigned int const Max_size;
		data *stack;
		short int top;
	public:
		SStack(unsigned int);
		SStack(const SStack&);
		void Clear();
		int Size();
		bool Empty();
		bool Full();
		data Pop();
		void Push(data);
		void List();
		~SStack();
};

#endif
