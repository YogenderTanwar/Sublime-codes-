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
int dis[18][18];

int x[18], y[18], z[18];
int n, all_vis;

int dp[200005][18];

/*

Iterative dp where dp[mask][node] stores its best value

for (int i = 0; i < n; i++) dp[(1ll << i)][i] = val[i];


		for (int mask = 0; mask < (1ll << n); mask++)
		{
			for (int node = 0; node < n; node++)
			{
				if (mask & (1 << node))
				{
					for (int i = 0; i < n; i++)
					{
						if ((mask & (1 << i)) == 0)
						{
							dp[mask | (1 << i)][i] = max(dp[mask | (1 << i)][i], val[i] + dis[node][i] + dp[mask][node]);

						}
					}
				}
			}
		}

*/

int solve(int mask, int node)
{
	if (mask == all_vis)
	{
		return dis[node][0];
	}

	int &res = dp[mask][node];
	if (res != -1) return res;
	res = inf;


	for (int i = 0; i < n; i++)
	{
		if (((1 << i)&mask) == 0)
		{
			int val = dis[node][i] + solve((mask) | (1 << i) , i);

			res = min(res, val);
		}
	}

	return res;

}





signed   main()
{
	fast
	int t = 1;
	//cin >> t;
	while (t--)
	{

		cin >> n;
		all_vis = (1 << n) - 1;

		for (int i = 0; i < (1 << n); i++)
		{
			for (int j = 0; j < n; j++) dp[i][j] = -1;

		}


		for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> z[i];


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dis[i][j] = (abs(x[i] - x[j]) + abs(y[i] - y[j]) + max(0ll, z[j] - z[i]));
				//cout << dis[i][j] << " ";
			}
			//cout << endl;

		}

		cout << solve(1, 0);











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



