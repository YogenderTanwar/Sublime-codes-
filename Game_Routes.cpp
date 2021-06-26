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
vector<ll> arr[100005];
ll vis[100005];
ll dp[100005];
 ll n,m;

void dfs(ll node)
{
     vis[node]=1;
   //  dbg(node);


     if(node==n)
     {
         vis[node]=1;

         dp[node]=1;
         return ;

     }

     for(auto x: arr[node])
     {
         
           if(vis[x]) {
                dp[node]=(dp[node]+dp[x])%MOD;
                continue;
           } 
           dfs(x);

            dp[node]=(dp[node]+dp[x])%MOD;
          


     }
   

     }


int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
       
        cin>>n>>m;

        for(ll i=1;i<=m;i++)
        {
            ll u,v;
            cin>>u>>v;
            arr[u].push_back(v);

        }

        dfs(1);

        cout<<dp[1]<<endl;


        
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
 