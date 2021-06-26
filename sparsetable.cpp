#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define jaldi_chal  ios_base::sync_with_stdio(0); cin.tie(0);
#define tr(c,i) for(auto i=(c).begin(); i != (c).end(); i++)
#define REP(i,k) for( ll i=0;i<k;i++)
#define REW(i,a,b) for(ll i=a;i<=b;i++)
#define M 1000000007
#define F first
#define dbg(x)  cout<<#x<<" " <<x<<endl;
#define S second
#define inf 1e10
#define endl "\n"
ll power(ll a , ll b)
{
	ll res = 1;
	while (b)
	{
		if (b % 2)
		{

			b--;
			res = res * a;
		}
		else {
			b = b / 2;
			a = a * a;
		}

	}
	return res;
}

int main() {
	jaldi_chal
	ll t, i;
	ll n;
	cin >> n;
	ll a[n];
	REP(i, n) cin >> a[i];
	ll w = floor(log2(n));

	ll sp[n][w + 1];

	REP(i, n) sp[i][0] = i;


	for (ll j = 1; power(2, j) <= n; j++)
	{

		for (ll i = 0; i + power(2, j) - 1 < n; i++)
		{
			if (a[sp[i][j - 1]] < a[sp[i + power(2, j - 1)][j - 1]])
			{
				sp[i][j] = sp[i][j - 1];
			}
			else sp[i][j] = sp[i + power(2, j - 1)][j - 1];

		}
	}




	ll q;
	cin >> q;

	while (q--)
	{
		ll l, r;
		cin >> l >> r;

		ll diff = (r - l + 1);
		ll val;
		if (diff > 0)
			val = floor(log2(diff));
		else {
			cout << a[l] << endl;
			continue;
		}

		ll x = r - pow(2, val) + 1;
		ll ans = (min(a[sp[l][val]], a[sp[x][val]]));
		cout << ans << endl;

	}




	return 0;
}
