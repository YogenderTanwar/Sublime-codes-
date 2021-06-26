#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define MOD 1000000007
const ll inf = 1e18;
ll power(ll a, ll b);
vector<tuple<ll, ll, ll> > arr;
ll dis[100005];
ll parent[100005];



ll   solve(ll n)
{
	ll x;
	for (ll i = 1; i <= n; i++)
	{
		x = -1;

		for (auto [a, b, w] : arr)
		{
			if (dis[b] > dis[a] + w)
			{
				dis[b] = dis[a] + w;
				parent[b] = a;
				x = b;




			}

		}
	}
	return x;


}



int main()
{
	fast
	ll t = 1;
	//cin >> t;
	while (t--)
	{
		ll n, m;
		cin >> n >> m;

		memset(parent, -1, sizeof parent);


		for (ll i = 0; i < m; i++)
		{
			ll u, v, w;
			cin >> u >> v >> w;
			arr.push_back({u, v, w});

		}

		ll val = solve(n);
		if (val == -1)
		{
			cout << "NO" << endl;
		}
		else {

			for (ll i = 1; i < n; i++)
			{
				val = parent[val];


			}
			vector<ll> cycle;

			for (ll v = val; ; v = parent[v])
			{
				cycle.push_back(v);
				if (v == val && cycle.size() > 1)
				{
					break;
				}

			}
			cout << "YES" << endl;

			reverse(all(cycle));

			for (auto x : cycle) cout << x << " ";
			cout << endl;





		}






	}
	return 0;
}

ll power(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b % 2) b-- , res = res * a;
		else b = b / 2 , a *= a;
	}
	return res;
}
