#include<bits/stdc++.h>
using namespace std;
#define int long long //delete if causing problems
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define setbit(n) __builtin_popcountll(n)
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

		// for (int mask = 0; mask < (1 << N); ++mask) { // O(4^n)
		// 	for (int i = 0; i < (1 << N); ++i) {
		// 		if ((mask & i) == i) {
		// 			F[mask] += A[i];
		// 		}
		// 	}
		// }

		// for (int mask = 0; mask < (1 << n); mask++) { // O(3^n)
		// 	F[mask] = A[0];
		// 	// iterate over all the subsets of the mask
		// 	for (int i = mask; i > 0; i = (i - 1) & mask) {
		// 		F[mask] += A[i];
		// 	}
		// }

		// O(n*2^n)

		int n;
		cin >> n;

		int f[1 << n];

		for (int i = 0; i < (1 << n); i++) cin >> f[i];


		int dp[(1 << n)][n + 1];
		// base condition
		for (int t = 0; t < (1ll << n); t++)
		{
			dp[t][0] = f[t];
		}

		for (int t = 0; t < (1ll << n); t++)
		{


			for (int i = 1; i <= n; i++)
			{

				if ((t) & (1ll << i - 1)) // on
				{
					dp[t][i] = dp[t][i - 1] + dp[(t ^ (1ll << i - 1))][i - 1];


				}
				else {
					dp[t][i] = dp[t][i - 1];
				}

			}
		}

		for (int t = 0; t < (1ll << n); t++) cout << dp[t][n] << " ";






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



