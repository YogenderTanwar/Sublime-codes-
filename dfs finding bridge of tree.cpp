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
vector<ll> arr[10001];
ll vis[10001];
ll low[10001],in[10001];
ll timer=0;

void dfs(ll node ,ll par)
{
	vis[node]=1;
	low[node]=in[node]=timer++;

	for(auto x: arr[node])
	{
		if(x==par) continue;
		if(vis[x])
		{
			// back edge 
		//	cout<<node <<" "<<x<<endl;
			low[node]=min(low[node],in[x]);

		}
		else {

			// forward edge

			dfs(x,node);
           
         //  cout<<"hi"<<" "<<node <<" "<<x<<endl;
			if(low[x]>in[node]) cout<<"bridge"<<node<<" --"<<x<<endl;

			low[node]=min(low[node],low[x]);
		}
	}


}




int main() {
jaldi_chal
ll t,i;

 ll n,m;
 cin>>n>>m;

 REP(i,m)
 {
	 ll u,v;
	 cin>>u>>v;
	 arr[u].push_back(v);
	 arr[v].push_back(u);

 }

 dfs(1,-1);



	return 0;
}
