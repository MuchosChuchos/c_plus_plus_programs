#ifndef QUEUE_H
#define QUEUE_H
typedef char data;
class Queue
{
	private:
		unsigned int const Max_size;
		data *queue;
		short int top, bottom;
	public:
		Queue(unsigned int);
		Queue(const Queue&);
		void Clear();
		int Size();
		bool Empty();
		bool Full();
		data Pop();
		void Push(data);
		void List();
		~Queue();
};

#endif
