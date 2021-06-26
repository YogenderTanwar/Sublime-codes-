#include<iostream>
#include<queue>
#include<stack>
using namespace std;


// class stack
// {
// // private:
// // 	int top1 = -1;
// // 	int max = 100;
// // 	int arr[100];

// // public:

// // 	void pop()
// // 	{
// // 		if (top1 == -1)
// // 		{
// // 			cout << "stack underflow";
// // 			abort();

// // 		}

// // 		top1--;


// // 	}

// // 	int top()
// // 	{
// // 		if (!isempty())
// // 			return arr[top1];
// // 		else {
// // 			cout << "No element in the stack";
// // 			abort();

// // 		}

// // 	}

// // 	void push(int data)
// // 	{
// // 		if (top1 >= 99)
// // 		{
// // 			cout << "Overflow";
// // 			abort();
// // 		}
// // 		else {
// // 			top1++;
// // 			arr[top1] = data;


// // 		}
// // 	}

// // 	bool  isempty()
// // 	{

// // 		if (top1 == -1) return true;
// // 		else return false;


// // 	}

// public :

// 	queue<int > q1, q2;

// 	void push(int data)
// 	{
// 		q2.push(data);

// 		while (!q1.empty())
// 		{
// 			q2.push(q1.front());
// 			q1.pop();
// 		}

// 		swap(q1, q2);

// 	}

// 	void pop()
// 	{
// 		q1.pop();
// 	}

// 	int top()
// 	{
// 		return q1.front();

// 	}

// 	bool is_empty()
// 	{
// 		if (q1.size() == 0) return true;
// 		else return false;

// 	}



// };

void solve( int a[], int n)
{
	stack<int > s;

	s.push(a[0]);
	//cout << n << endl;

	for (int i = 1; i < n; i++)
	{
		if (s.empty())
		{
			s.push(a[i]);
			continue;

		}
		//cout << s.top() << " " << a[i] << endl;

		while (s.empty() == false && s.top() < a[i])
		{
			cout << s.top() << " -----> " << a[i] << endl;
			s.pop();

		}

		s.push(a[i]);
	}

	while (!s.empty())
	{
		cout << s.top() << " -----> " << "-1" << endl;
		s.pop();

	}
}






int main()
{

	// stack s;
	// s.push(10);
	// s.push(1);
	// s.push(15);
	// s.push(125);
	// s.push(1036);
	// // s.pop();


	// while (!s.is_empty())
	// {
	// 	cout << s.top() << " ";
	// 	s.pop();

	// }

	int arr[] = {11, 13, 21, 3};
	int n = sizeof(arr) / sizeof(arr[0]);

	solve(arr, n);


	return 0;

}