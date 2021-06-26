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
ll a[1003][1003];


int main()
{
    fast
    ll t = 1; 
    cin >> t;
   for(ll tt=1;tt<=t;tt++)
    {
        ll ans=0;

        ll n;
        cin>>n;
        for(ll i=1;i<=n;i++) 
        {
            for(ll j=1;j<=n;j++) cin>>a[i][j];
        }

        for(ll j=1;j<=n;j++)
        {
            ll temp=0;
            ll k=0;

             for(ll i=1;i<=n-j+1;i++)
             {
                 temp+=a[i][j+k];
                 k++;


                  
             }
             //dbg(temp);

             ans=max(ans,temp);
        }

         for(ll i=1;i<=n;i++)
        {
            ll temp=0;
            ll k=0;

             for(ll j=1;j<=n-i+1;j++)
             {
                 temp+=a[i+k][j];
                 k++;


                  
             }
          //   dbg(temp);

             ans=max(ans,temp);
        }

    cout<<"Case #"<<tt<<": "<<ans<<endl;

        
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
 