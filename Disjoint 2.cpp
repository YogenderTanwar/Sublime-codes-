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
ll parent[100001];

ll find(ll a)
{
	if (parent[a] < 0) return a;

	return parent[a] = find(parent[a]);

}


void Union(int a, int  b)
{
	parent[b] += parent[a];
	parent[a] = b;

}





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
		memset(parent , -1, sizeof(parent));

		ll n, m, q;
		cin >> n >> m;


		for (ll i = 1; i <= m; i++)
		{
			ll u, v;
			cin >> u >> v;


			ll a = find(u);
			ll b = find(v);

			// dbg(a);
			// dbg(b);



			if (a > b) swap(a, b);

			if (a != b)
			{

				Union(a, b);

			}

		}

		//REW(i, 1, 7) cout << parent[i] << " ";



		cin >> q;

		while (q--)
		{
			ll u, v;
			cin >> u >> v;

			if (find(u) > find(v)) cout << u << endl;
			else if (find(v) > find(u)) cout << v << endl;
			else cout << "TIE" << endl;
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