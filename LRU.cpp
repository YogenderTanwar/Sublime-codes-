#include<bits/stdc++.h>
using namespace std;

class LRU
{
public:
	list<int> q;
	unordered_map<int , list<int> :: iterator> m;

	int size = 0;


	LRU(int a)
	{
		size = a;

	}

	void refer(int a)
	{
		if (m.find(a) == m.end())
		{
			if (q.size() == size)
			{
				int last = q.back();

				q.pop_back();

				m.erase(last);
			}



		}
		else {
			q.erase(m[a]);

		}

		q.push_front(a);

		m[a] = q.begin();
	}


	void display()
	{
		for (auto x : q) cout << x << " ";

	}



};


int main()
{

	LRU ca(4);

	ca.refer(1);
	ca.refer(2);
	ca.refer(3);
	ca.refer(1);
	ca.refer(4);
	ca.refer(5);
	ca.display();



	return 0;

}