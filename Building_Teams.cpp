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
vector<ll> arr[100004];
ll vis[100004];
ll color[100004];

bool dfs(ll node,ll col)
{
 //   dbg(node);

     vis[node]=1;
     color[node]=col;

     for(auto x: arr[node])
     {
         if(vis[x]==0)  if(!dfs(x,col^1)) return false;
         
          
        
          if(color[x]==color[node]) {
             // dbg(x);
              return false;

          }

     }
     return true;

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

        for(ll i=1;i<=m;i++)
        {
            ll u,v;
            cin>>u>>v;
            arr[u].push_back(v);
            arr[v].push_back(u);

        }
        ll flag=0;
        for(ll i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            if(!dfs(i,0)) 
            {
                flag=1;
                break;
            }
           
        }
        if(flag==1) cout<<"IMPOSSIBLE"<<endl;
        else {
            for(ll i=1;i<=n;i++) 
            {
                if(color[i]) cout<<"1"<<" ";
                else cout<<"2"<<" ";

            }
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
 