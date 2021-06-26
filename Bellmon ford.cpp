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
	// cin >> t;
	while (t--)
	{

		ll n, m;
		cin >> n >> m;

		// {{u,v},w}
		//directed

		vector<pair<pair<ll, ll> , ll> > a;

		vector<ll> dis(n + 1, inf);

		dis[1] = 0; // source



		for (ll i = 1; i <= m; i++)
		{
			ll u, v, w;
			cin >> u >> v >> w;

			a.push_back({{u, v}, w});


		}

		for (ll j = 1; j <= n - 1; j++)
		{
			for (ll i = 0; i < a.size(); i++)
			{
				ll parent_node = a[i].F.F;
				ll child_node = a[i].F.S;
				ll weight = a[i].S;

				if (dis[parent_node] != inf && dis[child_node] > dis[parent_node] + weight)
				{
					dis[child_node] = dis[parent_node] + weight;


				}
			}
		}


		for (ll i = 0; i < a.size(); i++)
		{
			ll parent_node = a[i].F.F;
			ll child_node = a[i].F.S;
			ll weight = a[i].S;

			if (dis[parent_node] != inf && dis[child_node] > dis[parent_node] + weight)
			{
				cout << "Contain negative cycle" << endl;


			}
		}


		for (ll i = 1; i <= n; i++)
		{
			cout << dis[i] << " ";

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