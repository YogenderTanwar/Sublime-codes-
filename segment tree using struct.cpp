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
ll arr[50005];
struct tree{
	ll pre,su,bst,sum;
	
} stree[200005];
void bulid(ll si,ll ss,ll se)
{
	if(ss==se)
	{
		stree[si].bst=stree[si].pre=stree[si].su=stree[si].sum=arr[ss];
		return ;
	}
	ll mid=(ss+se)/2;
	(bulid(2*si,ss,mid));
	bulid(2*si+1,mid+1,se);
	
	stree[si].bst=max(stree[2*si].su+stree[2*si+1].pre,max(stree[2*si].bst,stree[2*si+1].bst));
	stree[si].sum=stree[2*si].sum+stree[2*si+1].sum;
	stree[si].pre=max(stree[2*si].sum+stree[2*si+1].pre,stree[2*si].pre);
	stree[si].su=max(stree[2*si+1].su,stree[2*si].su+stree[2*si+1].sum);	
}

tree query(ll si,ll ss,ll se,ll qs,ll qe)
{
	tree t;
	if(qs>se||(qe<ss)||(qs>qe))
	{
			t.bst=t.pre=t.su=INT_MIN;
			t.sum=0;
			return t;
	}
	
	if(qs<=ss&&(qe>=se))
	{
		return stree[si];
	}
	ll mid=(ss+se)/2;
	tree q1=query(2*si,ss,mid,qs,qe);
	tree q2=query(2*si+1,mid+1,se,qs,qe);
	
	t.sum=q1.sum+q2.sum;
	t.bst=max(q1.su+q2.pre,max(q1.bst,q2.bst));
	t.pre=max(q1.pre,q1.sum+q2.pre);
	t.su=max(q2.su,q2.sum+q1.su);
	
	return t;
}

int main() {
jaldi_chal
ll n;
cin>>n;
REW(i,1,n) cin>>arr[i];
bulid(1,1,n);

ll q;
cin>>q;
while(q--)
{
	ll l,r;
	cin>>l>>r;
	cout<<query(1,1,n,l,r).bst<<endl;
}

	return 0;
}
