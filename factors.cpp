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
ll solve(ll n)
{
	ll count=0;
	for(ll i=1;(i*i)<n;i++)
	{
		if(n%i==0)
		{
			count++;
			if((n/i)==i) cout<<i<<endl;
			cout<<i<<" "<<(n/i)<<endl;
		}
	}
	return count;
}

int main() {
jaldi_chal
ll t,i;

	
	ll count=0;
	ll n;
	cin>>n;
ll ans=	solve(n);
	
	cout<<" value"<<" "<<ans*2<<endl;





	return 0;
}
