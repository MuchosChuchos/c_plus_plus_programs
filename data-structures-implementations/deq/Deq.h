#ifndef DEQ_H
#define DEQ_H
typedef char data;
class Deq
{
	private:
		unsigned int const Max_size;
		data *deq;
		short int left, right;
		unsigned int size;
	public:
		Deq(unsigned int);
		Deq(Deq&);
		void Clear();
		int Size();
		bool Empty();
		bool Full();
		data Pop_Left();
		data Pop_Right();
		void Push_Left(data);
		void Push_Right(data);
		void List();
		~Deq();
};

#endif
