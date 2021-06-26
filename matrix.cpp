#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long 
#define jaldi_chal  ios_base::sync_with_stdio(0); cin.tie(0);
#define tr(c,i) for(auto i=(c).begin(); i != (c).end(); i++)
#define REP(i,k) for( ll i=0;i<k;i++)
#define REW(i,a,b) for(ll i=a;i<=b;i++)
#define M 1000000000
#define F first
#define dbg(x)  cout<<#x<<" " <<x<<endl;
#define S second
#define inf 1e10
#define endl "\n"

ll arr[12][12];
void show (ll a[12][12],ll k)
{
	REW(i,1,k) 
	{
		REW(j,1,k) cout<<a[i][j]<<" ";
		cout<<endl;
	}
}

void  mul(ll a[12][12],ll b[12][12],ll k)
{
	ll c[12][12];
	
	REW(i,1,k)
	{
		REW(j,1,k)
		{
			c[i][j]=0;
			REW(z,1,k)
			{
				c[i][j]=(a[i][z]%M*(b[z][j]%M)%M+(c[i][j]))%M;
			}
		}
	}
	
		REW(i,1,k)
	{
		REW(j,1,k) a[i][j]=c[i][j];
		}	
	
	
}

void power(ll a[12][12],ll p,ll k)
{
	ll res[12][12];
		memset(res,0,sizeof(res));
		
		REW(i,1,k) res[i][i]=1;
		
		while(p)
		{
			if(p)
			{
				p--;
				mul(res,a,k);
			}
			else {
				p=p/2;
				mul(a,a,k);
			}
		}
		
	REW(i,1,k)
	{
		REW(j,1,k) a[i][j]=res[i][j];
		}	
	
	
}

int main() {
jaldi_chal
ll t,i;
cin>>t;

while(t--)
{
   ll k;
   cin>>k;
   ll b[k+1];
   ll c[k+1];
   REW(i,1,k) cin>>b[i];
    REW(i,1,k) cin>>c[i];
    
    ll n;
    cin>>n;
    if(n<=k)
    {
      cout<<b[n]<<endl;	
	}
	else {
		memset(arr,0,sizeof(arr));
		
		ll x=2;
		for(ll j=1;j<=k;j++)
		{
			for(ll i=1;i<=k;i++)
			{
				if(j==k)
				{
				   arr[i][j]=c[k+1-i];	
				}
				
				if(i==x)
				{
					arr[i][j]=1;
					x++;
					break;
				}
			}
		}
		
	
		
		power(arr,(n-k),k);
		
		ll ans=0;
	
		REW(i,1,k)
		{
			ans= (ans%M+(b[i]%M*(arr[i][k])%M)%M)%M;
		}
	   cout<<ans<<endl;
	}
   

}


	return 0;
}
