
#include <bits/stdc++.h>
using namespace std;
using ll = long long ;


vector<ll> a[100];

ll vis[100];


stack<ll> s;


void top(ll node )
{

	vis[node] = 1;
	ll flag = 0;

	for (auto x : a[node])
	{
		if (vis[x]) continue;

		flag = 1;
		top(x);
	}

	s.push(node);

}



int main()
{

	ll n = 8;

	a[1].push_back(3);
	a[2].push_back(3);
	a[2].push_back(4);
	a[4].push_back(6);
	a[3].push_back(5);
	a[5].push_back(6);
	a[5].push_back(8);
	a[6].push_back(7);

	for (ll i = 1; i <= 8; i++)
	{
		if (vis[i] == 0)
		{
			top(i);
		}

	}

	while (!s.empty())
	{
		cout << s.top() << " ";

		s.pop();

	}




	return 0;
}

