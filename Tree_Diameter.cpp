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
vector<ll> arr[300001];

ll a[300001],b[300001];
ll ans=0;




void dfs(ll node, ll par)
{
    a[node]=b[node]=1;
    ll x=-1,y=-1;

    for(auto child: arr[node])
    {
         if(child==par) continue;
         dfs(child,node);

         x=max(x,a[child]);

         if(x>y) swap(y,x);

    }

    a[node]+=y;

    b[node]+=(x+y+1);

   // cout<<a[node]<<" "<<b[node]<<endl;

    ans=max(ans,max(a[node],b[node]));


}



int main() {


	jaldi_chal
	ll t = 1, i;
	// cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;

		REW(i, 1, n - 1)
		{
			ll u, v;
			cin >> u >> v;

			arr[u].push_back(v);
			arr[v].push_back(u);
		}
        dfs(1,-1);


        cout<<ans<<endl;




		















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