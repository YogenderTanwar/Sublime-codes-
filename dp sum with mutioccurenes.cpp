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



int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	jaldi_chal
	ll t = 1, i;

	while (t--)
	{
		ll cost[26];

		REP(i, 26) cin >> cost[i];

		ll target;
		cin >> target;
		//dbg(target);



		ll dp[27][target + 4];

		for (ll i = 0; i <= target; i++)
		{
			for (ll j = 0; j < 26; j++)
			{
				if (i == 0) dp[j][i] = 0;
				else dp[j][i] = -1;


			}
		}

		ll len = 0;

		for (ll i = 0; i < 26; i++)
		{
			for (ll j = 1; j <= target; j++)
			{
				for (ll k = 0; k <= i ; k++)
				{
					if (j - cost[i] >= 0  && dp[i - k][j - cost[i]] != -1)
					{
						dp[i][j] = max(dp[i][j], dp[i - k][j - cost[i]] + 1);


					}

					if (j == target) len = max(dp[i][j], len);
				}

				// cout << dp[i][j] << " ";
			}
			//cout << endl;
		}

		vector<char> ans;
		i = 25;


		while ( target > 0 && i > 0 && len > 0)
		{
			if (dp[i][target] == len)
			{
				//cout << i << " " << target << endl;
				ans.push_back('a' + i);
				target -= cost[i];
				len--;

			}
			else i--;

		}

		for (auto x : ans) cout << x;
		cout << endl;









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