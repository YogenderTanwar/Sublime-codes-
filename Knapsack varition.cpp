#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define jaldi_chal  ios_base::sync_with_stdio(0); cin.tie(0);
#define tr(c,i) for(auto i=(c).begin(); i != (c).end(); i++)
#define REP(i,k) for( ll i=0;i<k;i++)
#define REW(i,a,b) for(ll i=a;i<=b;i++)
#define MOD 1000000007
#define F first
#define dbg(x)  cout<<#x<<" " <<x<<endl;
#define S second
#define inf 1e10
#define endl "\n"
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
ll power(ll a, ll b);
ll dp[101][100001];




int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	jaldi_chal
	ll t = 1, i;
	// cin >> t;
	while (t--)
	{
		ll n, w;
		cin >> n >> w;

		ll weight[n + 1], val[n + 1];

		for (ll i = 1; i <= n; i++)
		{
			dp[i][0] = 0;

			for (ll j = 1; j <= 100000; j++)
			{

				dp[i][j] = inf;


			}
		}

		REW(i, 1, n) cin >> weight[i] >> val[i];




		dp[1][val[1]] = weight[1];

		for (ll i = 2; i <= n; i++)
		{
			dp[i][0] = 0;

			for (ll j = 1; j <= 100000; j++)
			{

				if (j < val[i]) dp[i][j] = dp[i - 1][j];

				else {

					dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - val[i]] + weight[i]);
				}

			}
		}



		for (ll i = 100000; i >= 1; i--)
		{
			if (dp[n][i] <= w)
			{
				cout << i;
				break;
			}
		}












	}


	return 0;
}


ll power(ll a, ll b) {
	ll res = 1;
	while (b)
	{
		if (b % 2) b-- , res = res * a;
		else b = b / 2 , a *= a;
	}
	return res;
}