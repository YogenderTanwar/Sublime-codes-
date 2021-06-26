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
char arr[100001];
struct tree{

  bitset<26> bit;
	
} stree[400005];
void bulid(ll si,ll ss,ll se)
{
	//cout<<"hello"<<" "<<ss<<" "<<se<<endl;
	if(ss==se)
	{
	
	//	cout<<stree[si].c<<endl;
	stree[si].bit[arr[ss]-'a']=1;
		return ;
	}
	ll mid=(ss+se)/2;
	(bulid(2*si,ss,mid));
	bulid(2*si+1,mid+1,se);
	
	stree[si].bit=(stree[2*si].bit|stree[2*si+1].bit);
//	cout<<si<<" "<<stree[si].c<< " "<<stree[si].s.size()<<endl;
}

tree query(ll si,ll ss,ll se,ll qs,ll qe)
{
	tree t;
	if(qs>se||(qe<ss)||(qs>qe))
	{
		
	    
			return t;
	}
	
	if(qs<=ss&&(qe>=se))
	{
		return stree[si];
	}
	ll mid=(ss+se)/2;
	tree q1=query(2*si,ss,mid,qs,qe);
	tree q2=query(2*si+1,mid+1,se,qs,qe);
	
    t.bit=(q1.bit|q2.bit);
	return t;
}
void update(ll si,ll ss,ll se,ll qi) 
{
	
	if(ss==se)
	{
	     
	     stree[si].bit=0;
	      stree[si].bit[arr[ss]-'a']=1;
		return;
	}
	ll mid=(ss+se)/2;
	
	if(qi<=mid)  	update(2*si,ss,mid,qi);
	else 	update(2*si+1,mid+1,se,qi);
	stree[si].bit=(stree[2*si].bit|stree[2*si+1].bit);
   
}



int main() {
jaldi_chal
ll n;
string str;
cin>>str;
n=str.size();
REW(i,1,str.size())
{
	arr[i]=str[i-1];
	//	cout<<arr[i];
}
bulid(1,1,str.size());
ll q;
cin>>q;
while(q--)
{
    ll type;
    cin>>type;
    if(type==1)
    {
        ll pos;
        char c;
        cin>>pos>>c;
        arr[pos]=c;
        update(1,1,n,pos);
        
    }
    else{
        ll l,r;
        cin>>l>>r;
        cout<<query(1,1,n,l,r).bit.count()<<endl;
        
    }
    
}







	return 0;
}
