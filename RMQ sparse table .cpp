#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define jaldi_chal  ios_base::sync_with_stdio(0); cin.tie(0);
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
ll a[100001];
ll sp[100001][20]; // check for runtime error



int main() {


	jaldi_chal
	ll t = 1, i;
	// cin >> t;
	while (t--)
	{

		ll n;
		cin >> n;

		for (ll i = 1; i <= n; i++)
		{
			cin >> a[i];

		}

		ll maxN = floor(log2(n));


		for (ll i = 1; i <= n; i++)
		{
			sp[i][0] = i;

		}


		for (ll j = 1; power(2, j) <= n; j++)
		{
			for (ll i = 1; i + power(2, j) - 1 <= n; i++)
			{


				if (a[sp[i][j - 1]] < a[sp[i + power(2, j - 1)][j - 1]])
				{
					sp[i][j] = sp[i][j - 1];
				}
				else sp[i][j] = sp[i + power(2, j - 1)][j - 1]; // index based min sparse table

			}

		}





		ll q;

		cin >> q;

		while (q--)
		{
			ll l, r;
			cin >> l >> r;


			ll diff = (r - l + 1);
			//dbg(diff);

			ll val;


			val = floor(log2(diff));




			cout << min(a[sp[l][val]], a[sp[r - power(2, val) + 1][val]]) << endl;



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