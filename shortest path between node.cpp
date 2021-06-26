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
#define inf 1e9
#define endl "\n"
vector<ll> arr[200001];
ll da[200001],db[200001],dc[200001];


void bfs(ll node ,ll d[])
{
	d[node]=0;
	queue<ll> q;
	q.push(node);
	while(!q.empty())
	{
		ll curr=q.front();
		q.pop();
		
		for(auto x: arr[curr])
		{
			if(d[x]==inf) 
		{
				d[x]=d[curr]+1;
			q.push(x);
			}
		}
	}
}


int main() {
jaldi_chal
ll t,i;
cin>>t;
while(t--)
{
ll n,m,a,b,c;
cin>>n>>m>>a>>b>>c;

ll weight[m];

REW(i,1,n) da[i]=inf , db[i]=inf , dc[i]= inf , arr[i].clear();
REP(i,m) cin>>weight[i];
sort(weight,weight+m);
ll u,v;
REP(i,m)  cin>>u>>v , arr[u].push_back(v) , arr[v].push_back(u);

ll pref[m+1]={0};

REP(i,m) pref[i+1]=pref[i]+weight[i];


 

bfs(a,da);
bfs(b,db);
bfs(c,dc);

ll ans=1e18;


for(ll i=1;i<=n;i++)
{
	
	 if(da[i]+db[i]+dc[i]>m) continue;
//	 cout<<i<<" "<<da[i]<<" "<<db[i]<<" "<<dc[i]<<endl;
	 ans=min(ans,pref[db[i]] + pref[da[i]+db[i]+dc[i]]);
	 
	 
	 
}

cout<<ans<<endl;







}


	return 0;
}
