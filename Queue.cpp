#include<iostream>
using namespace std;

class Queue
{

private:
	int front = 0, rear = -1, size;
	int arr[10000];

public:

	void push(int data)
	{
		rear++;
		arr[rear] = data;
		size++;


	}

	bool isempty()
	{
		if (size == 0) return true;
		else return false;

	}

	int start()
	{
		if (isempty()) cout << "NO element" , abort();

		else return arr[front];

	}

	int back()
	{
		if (isempty()) cout << "NO element" , abort();

		else return arr[rear];

	}

	void pop()
	{
		front++;
		size--;


	}



};











int main()
{

	Queue q;

	q.push(8);
	q.push(10);
	q.push(15);
	q.push(8415);
	q.pop();

	q.push(151);

	while (!q.isempty())
	{
		cout << q.start() << " ";
		q.pop();

	}

	return 0;

}
