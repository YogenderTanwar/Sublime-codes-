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
const int N = 100005;
vector<int > arr[N];
int   vis[N] ;
int  maxN = log2(N);
int  lca[N][20]; // check this always
int  level[N];


void dfs(int  node, int  par, int  d)
{
	lca[node][0] = par;
	level[node] = d;
	for (auto x : arr[node])
	{
		if (x == par) continue;
		dfs(x, node, d + 1);
	}
}



void build(int  n) // table for lca
{
	dfs(1, -1, 0); // par;

	for (int  j = 1; j <= maxN; j++)
	{
		for (int  i = 1; i <= n; i++)
		{
			if (lca[i][j - 1] != -1)
			{
				int  val = lca[i][j - 1];
				lca[i][j] = lca[val][j - 1];
			}

		}
	}


}

int  getLCA(int  a, int  b)
{
	if (level[a] > level[b]) swap(a, b);

	int  d = level[b] - level[a];

	while (d > 0)
	{
		int  i = log2(d);
		b = lca[b][i];
		d -= (1ll << i);
	}

	if (a == b) return a;

	for (int  i = maxN; i >= 0; i--)
	{
		if (lca[a][i] != -1 && lca[a][i] != lca[b][i])
		{
			a = lca[a][i] , b = lca[b][i];
		}
	}

	return lca[a][0];

}

int  getdis(int  a, int  b)
{
	int  val = getLCA(a, b);

	return level[a] + level[b] - 2 * level[val];
}

/*

 for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 20; j++) lca[i][j] = -1;

		}
  */



signed   main()
{
	fast
	int t = 1;
	//cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 20; j++) lca[i][j] = -1;

		}

		// dfs(1,-1,0);

		// build(n)

		// process the queries







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



