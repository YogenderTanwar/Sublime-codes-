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
map<ll,ll> m;
ll prime[1000001];
void seive()
{
	REW(i,1,1000000) prime[i]=i;
	
	for(ll i=2;i<=1000000;i+=2) prime[i]=2;
	for(ll i=3;i*i<=1000000;i++)
	{
		if(prime[i]==i) //no is prime
		{
			for(ll j=2*i;j<=1000000;j=j+i)
			{
				if(prime[j]==j) //no not touched yet
				prime[j]=i;
			}
		}
	}
	
}

void  factor(ll n)
{
	

	while(n!=1)
	{
		ll p=prime[n];
		 m[p]++;
		 n=n/p;
	}

}


int main() {
jaldi_chal
seive();
ll n=24;
factor(n);
factor(n);
for(auto x: m) cout<<x.F<<" "<<x.S<<endl;



	return 0;
}
