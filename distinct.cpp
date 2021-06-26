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

struct group {
	int l, r, id;

};

vector<int > bit;
int  n, q;

void update(int  index, int  val)
{

	while (index > 0 && index <= 500000)
	{
		//cout << index << " ";
		bit[index] += val; // change here
		index = index + (index & (-index));

	}
}

int  sum(int  index)
{
	int  val = 0;
	while (index > 0)
	{


		val += bit[index]; // change here
		index -= (index & (-index));

	}

	return val;

}
int a[300001];

/*

*/

int last_visit[500005];


bool comp(group a, group b)
{
	return b.r >= a.r;

}


signed   main()
{
	fast
	int t = 1;
	//cin >> t;
	while (t--)
	{
		int n, q;
		cin >> n >> q;
		bit.resize(500002);

		int a[n + 1];

		for (int i = 1; i <= n; i++) cin >> a[i];
		memset(last_visit, -1, sizeof last_visit);


		vector<group> query(q);
		vector<int> ans(q);



		for (int i = 0; i < q; i++)
		{
			int l, r;

			cin >> l >> r;
			query[i].l = l;
			query[i].r = r;
			query[i].id = i;


		}

		sort(all(query), comp);


		int j = 0;

		for (int i = 1; i <= n; i++)
		{
			if (last_visit[a[i]] != -1)
			{
				update(last_visit[a[i]], -1);
			}

			last_visit[a[i]] = i;
			update(i, 1);

			while (j < q && query[j].r == i)
			{
				//cout << query[j].l << " " << query[j].r << endl;

				ans[query[j].id] = sum(query[j].r) - sum(query[j].l - 1);
				//dbg(sum(query[j].r) - sum(query[j].l - 1));

				j++;


			}
		}

		for (auto x : ans) cout << x << endl;














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



