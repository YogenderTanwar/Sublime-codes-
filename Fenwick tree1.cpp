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

vector<ll> bit;
ll n, q;

void update(ll index, ll val)
{

	while (index > 0 && index <= n)
	{
		cout << index << " ";
		bit[index] += val;
		index = index + (index & (-index));

	}
}

ll sum(ll index)
{
	ll val = 0;
	while (index > 0)
	{


		val += bit[index];
		index -= (index & (-index));

	}

	return val;

}


int main() {


	jaldi_chal
	ll t, i;

	cin >> n >> q;

	bit.resize(n + 1);

	for (ll i = 0; i < n; i++) cin >> t  , update(i + 1, t)  ;



	for (ll i = 1; i <= n; i++) cout << bit[i] << " ";
	cout << endl;

	cout << sum(n) << endl;











	return 0;
}