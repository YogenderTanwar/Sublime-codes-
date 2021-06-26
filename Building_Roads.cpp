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
ll parent[100004];
ll find(ll node)
{
     if(parent[node]<0) return node;
     else return parent[node] = find(parent[node]);

}

void merge(ll a,ll b)
{ 
    parent[b]+=parent[a];
    parent[a]=b;
    
}


int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
        ll n,m;
        cin>>n>>m;
        memset(parent,-1,sizeof parent);

        for(ll i=1;i<=m;i++)
        {
             ll u,v;
             cin>>u>>v;
             if(find(u)!=find(v))
             {
                 merge(find(u),find(v));

             }
        }

        vector<ll> cnt;

        for(ll i=1;i<=n;i++) 
        {
             if(parent[i]<0) cnt.push_back(i);
        }

        cout<<cnt.size()-1<<endl;


        for(ll i=1;i<cnt.size();i++) 
        {
             cout<<cnt[0]<<" "<<cnt[i]<<endl;

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
 