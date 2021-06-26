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
vector<ll>  tree(100001,0);
void bulid(vector<ll> list)    //Fenwick Tree // O-based indices  
{
	REW(i,1,list.size())
	{
		tree[i]=list[i-1];
	}
	ll len=list.size();
	REW(i,1,len)
	{
		
		ll id=i+(i&(-i));
		cout<<i<<" "<<id<<endl;
		if(id<len+1) tree[id]+=tree[i];
	}
}

void print(ll n)
{
	REW(i,1,n) cout<<tree[i]<<" ";
	cout<<endl;
}

ll prefixquery(ll idx)
{
	int result = 0;
		for (++idx; idx > 0; idx -= idx & -idx) {
			result += tree[idx];
		}
		return result;
}

ll rangequery(ll a,ll b)
{
	if(a==0) return prefixquery(b);
	else return prefixquery(b)-prefixquery(a-1);
}

void update(ll idx, ll add) {
		
		for (++idx; idx < tree.size(); idx += idx & -idx) {
			tree[idx] += add;
		}
	}





int main() {
jaldi_chal
ll t,i;
vector<ll> s{1,2,5,4,3,8,6};
bulid(s);
update(2,7);
print(s.size());




	return 0;
}
