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
vector<ll> arr[100000];
ll vis[100000];
ll low[100000];
ll in[100000];

set<ll> points;

ll timer=1;
void dfs(ll node ,ll par)
{
	
	cout<<node<<" "<<par<<endl;
	vis[node]=1;
	in[node]=low[node]=timer++;
	ll children=0;
	for(auto child: arr[node])
	{
		if(child==par) continue;
		else if(vis[child]) 
		{
			// back edge 
			 
			 low[node]=min(in[child],low[node]);
		}
		else {
			
			dfs(child,node);
			low[node]=min(low[node],low[child]);
			
			if(low[child]>=in[node]&&par!=-1) points.insert(node);
			
			children++;
			
		}
	}
	
	if(par==-1 && (children>1) ) points.insert(node);
}

int main() {
jaldi_chal
ll t,i;
ll n,m;
cin>>n>>m;
REW(i,1,m)
{
	ll a,b;
	cin>>a>>b;
	arr[a].push_back(b);
	arr[b].push_back(a);
}

dfs(1,-1);

for(auto x: points) cout<<x<<" ";



	return 0;
}
