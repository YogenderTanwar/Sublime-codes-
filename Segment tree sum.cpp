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
ll arr[100]={0,1,5,2,7,9};
ll stree[400];
void bulid(ll si,ll ss,ll se)
{
	
	if(ss==se) {
		stree[si]=arr[ss];
return ;
	}
	ll mid=(ss+se)/2;
	bulid(2*si,ss,mid);
	bulid(2*si+1,mid+1,se);
	stree[si]=stree[2*si]+stree[2*si+1];
}

ll query(ll si,ll ss,ll se,ll qs,ll qe)
{
	if(qs>se||ss>qe) return 0;  
	
	if(ss>=qs&&se<=qe) return stree[si];
	ll mid=(ss+se)/2;
  ll l=	query((2*si),ss,mid,qs,qe);
ll r=query((2*si+1),mid+1,se,qs,qe);
	
	return (l+r);
}

void update(ll si,ll ss,ll se,ll qi) 
{
	
	if(ss==se)
	{
		stree[si]=arr[ss];
		return;
	}
	ll mid=(ss+se)/2;
	
	if(qi<=mid)  	update(2*si,ss,mid,qi);
	else 	update(2*si+1,mid+1,se,qi);
	
    stree[si]=(stree[2*si]+stree[2*si+1]);
}
int main() {
jaldi_chal
ll t,i;
ll n;
 
 
bulid(1,1,5);

REW(i,1,7) cout<<stree[i]<<" ";
cout<<endl;
cout<<query(1,1,5,3,5);
arr[2]=-2;

update(1,1,5,2);
//cout<<query(1,1,5,1,5);



	return 0;
}
