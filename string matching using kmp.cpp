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
ll arr[1000001];
void kmp(string s)
{
	arr[0] = 0;
	for (ll i = 1; i < s.size(); i++)
	{
		ll j = arr[i - 1];
		while (j > 0 && s[i] != s[j]) j = arr[j - 1];
		if (s[i] == s[j]) j++;
		arr[i] = j;


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
		string a, b;
		cin >> a >> b;
		kmp(b);

		set<ll> s;
		ll j = 0;
		ll lenb = b.size(), lena = a.size();
		ll i = 0;
		while (i < lena)
		{
			if (a[i] == b[j])
			{
				i++;
				j++;
			}
			if (j == lenb) s.insert(i - j + 1), j = arr[j - 1];

			else if (i < lena && a[i] != b[j])
			{
				if (j != 0) j = arr[j - 1];
				else i++;

			}

		}

		if (s.size() == 0) cout << "Not Found" << endl << endl;

		else {
			cout << s.size() << endl;
			for (auto x : s) cout << x << " ";
			cout << endl << endl;
		}






	}








	return 0;
}