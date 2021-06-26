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
ll d1[100001], d2[100001];

void mancher(string s)
{
	ll n = s.size();
	// odd length palindrome

	for (ll i = 0, l = 0, r = -1; i < n; i++)
	{
		ll k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);

		while (0 <= (i - k - 1) && i + k < n && s[i - k] == s[i + k] ) k++;
		d1[i] = k--;

		if ((i + k) > r)
		{
			l = i - k , r = i + k;
		}

	}

	for (ll i = 0, l = 0, r = -1; i < n; i++)
	{
		ll k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);

		while (0 <= (i - k - 1) && i + k < n && s[i - k - 1] == s[i + k] ) k++;
		d2[i] = k--;

		if ((i + k) > r)
		{
			l = i - k - 1 , r = i + k;
		}

	}



}



int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	jaldi_chal
	ll t, i;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;

		mancher(s);
		REP(i, s.size()) cout << d1[i] << " ";
		cout << endl;
		REP(i, s.size()) cout << d2[i] << " ";


	}








	return 0;
}