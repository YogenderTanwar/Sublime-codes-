#include<bits/stdc++.h>
using namespace std;
// #define int long long //delete if causing problems
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n" //delete if interactive
#define MOD 1000000007
const int inf = 1e18;
int power(int a, int b);


signed   main()
{
	fast
	int t = 1;
	//cin >> t;
	while (t--)
	{
		int q;
		cin >> q;

		map<int, int> m;
		set<unsigned int > s;
		m[0] = 1;
		s.insert(0);



		while (q--)
		{
			char c;
			cin >> c;
			if (c == '+')  {
				int val;
				cin >> val;
				m[val]++;

				if (m[val] == 1) s.insert(val);
			}
			else if (c == '-') {
				int val;
				cin >> val;
				m[val]--;
				if (m[val] == 0) s.erase(val);
			}
			else {
				int x;
				cin >> x;

				unsigned int y = ~x, l = 0, r;

				r = (x ^ y);

				for (int i = 31; i >= 0; i--)
				{

					if (y & (1ll << i))
					{

						if (s.lower_bound(l + (1 << i)) != s.end() && *s.lower_bound(l + (1 << i)) <= r)
						{
							l += (1 << i);
						}
						else r -= (1 << i);

					}
					else {

						if (s.lower_bound(l) != s.end() && *s.lower_bound(l) <= (r - (1ll << i)))
						{
							r -= (1ll << i);
						}
						else {
							l += (1ll << i);
						}
					}

				}

				cout << (x ^ l) << endl;





			}
		}




	}
	return 0;
}

int power(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b % 2) b-- , res = res * a;
		else b = b / 2 , a *= a;
	}
	return res;
}

/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long //delete if causing problems
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n" //delete if interactive
#define MOD 1000000007
const int inf = 1e18;
int power(int a, int b);

typedef struct node {
	node * a[2];
	int cnt = 0;
} trie;

trie* head;

void insert(int x)
{

	//dbg(x);

	trie* p = head;

	for (int i = 30; i >= 0; i--)
	{
		int currbit = (x >> i) & 1;



		if (p->a[currbit] == NULL)
		{
			// cout << "sd";

			p->a[currbit] = new trie();

		}
		p = p->a[currbit];
		p->cnt++;
	}

}


void remove(int x)
{
	trie* p = head;

	for (int i = 30; i >= 0; i--)
	{
		int currbit = (x >> i) & 1;
		p = p->a[currbit];
		p->cnt--;



	}
}


int maxxor(int x)
{
	trie* p = head;

	int ans = 0;

	for (int i = 30; i >= 0; i--)
	{
		int currbit = (x >> i) & 1;
		currbit ^= 1;

		if (p->a[currbit] != NULL && p->a[currbit]->cnt > 0)
		{
			ans += (1ll << i);
			p = p->a[currbit];
		}
		else {
			p = p->a[currbit ^ 1];

		}
	}

	return ans;

}



signed   main()
{
	fast
	int t = 1;
	//cin >> t;
	while (t--)
	{
		head = new trie();
		insert(0);
		int q;
		cin >> q;
		while (q--)
		{
			char ch;
			cin >> ch;
			int x;
			cin >> x;
			if (ch == '+')
				insert(x);
			else if (ch == '-')
				remove(x);
			else
				cout << maxxor(x) << endl;
		}




	}
	return 0;
}

int power(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b % 2) b-- , res = res * a;
		else b = b / 2 , a *= a;
	}
	return res;
}

/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/



