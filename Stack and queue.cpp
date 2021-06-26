#include<iostream>
using namespace std;


class stack
{
private:
	int top1 = -1;
	int max = 100;
	int arr[100];

public:

	void pop()
	{
		if (top1 == -1)
		{
			cout << "stack underflow";
			abort();

		}

		top1--;


	}

	int top()
	{
		if (!isempty())
			return arr[top1];
		else {
			cout << "No element in the stack";
			abort();

		}

	}

	void push(int data)
	{
		if (top1 >= 99)
		{
			cout << "Overflow";
			abort();
		}
		else {
			top1++;
			arr[top1] = data;


		}
	}

	bool  isempty()
	{

		if (top1 == -1) return true;
		else return false;


	}



};






int main()
{

	stack s;
	s.push(10);
	s.push(1);
	s.push(15);
	s.push(125);
	s.push(1036);
	// s.pop();


	while (!s.isempty())
	{
		cout << s.top() << " ";
		s.pop();

	}

	return 0;

}