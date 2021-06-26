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
const int p = 31;
const int m = 1e9 + 9;
ll p_pow[2000001];
ll h[2000001];





int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	jaldi_chal
	ll t, i;

	p_pow[0] = 1;

	REW(i, 1, 2000000)
	{
		p_pow[i] = (p_pow[i - 1] * p) % m;


	}
	ll n;
	while (cin >> n)
	{
		string a, b;



		cin >> b >> a;
		//	kmp(b);

		ll lena = a.size();
		ll lenb = b.size();
		h[0] = 0;


		for (ll i = 0; i < lena; i++)
		{
			h[i + 1] = (h[i] + (a[i] - 'a' + 1) * p_pow[i]) % m;

		}

		ll hs = 0;

		for (ll i = 0; i < lenb; i++)
		{
			hs = (hs + (b[i] - 'a' + 1) * p_pow[i]) % m;
		}

		set<ll> s;

		for (ll i = 0; i <= lena - lenb; i++)
		{
			ll curr = (h[i + lenb] + m - h[i]) % m;
			//cout << curr << " " << (hs * p_pow[i]) % m << endl;
			if ((hs * p_pow[i]) % m == curr) s.insert(i );

		}


		if (s.size() == 0) cout << endl << endl;

		else {

			for (auto x : s) cout << x << endl;
			//cout << endl << endl;
		}


	}



	return 0;
}