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
// o-based indexs 
ll arr[100000];
ll blk;  
ll b[1000];
  void bulid(ll n)
{
	blk=floor(sqrt(n));
	ll m=INT_MAX;
	ll count=0;
	ll j=0;
	for(ll i=0;i<n;i++)
	{
		m=min(m,arr[i]);
			count++;
		if(count==blk)
		{
			count=0;
			b[j++]=m;
			m=INT_MAX;
			
		}
	
		
	}
	if(count>0)   b[j++]=m;	
}


ll query(ll l,ll r)
{
	
	ll lb=l/blk;
	ll rb=r/blk;
	ll ans=INT_MAX;
	if(lb==rb)
	{
		REW(i,l,r)
		{
			ans=min(ans,arr[i]);
		}
	}
	else {
		
		for(ll i=l;i<(lb+1)*blk;i++)  ans=min(ans,arr[i]);
		
		for(ll i=lb+1;i<rb;i++) ans=min(ans,b[i]);
		
		for(ll i=(rb*blk);i<=r;i++)    ans=min(ans,arr[i]);
		
	}
	
	return ans;
	
}

int main() {
jaldi_chal
ll t,i;
ll n;
 cin>>n;
 REW(i,0,n-1) cin>>arr[i];
 bulid(n);
ll q;
cin>>q;
while(q--)
{
	ll l,r;
	cin>>l>>r;
	cout<<query(l,r)<<endl;
}



	return 0;
}
