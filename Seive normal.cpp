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
//not complete
int prime[100001];
void seive()
{
	for (int i = 1; i <= 100000; i++) prime[i] = 1;
	prime[1] = 0;
	for (int i = 2; i * i <= 100000; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= 100000; j = j + i)
			{

				prime[j] = 0;
			}
		}
	}

}


int main() {
	jaldi_chal
	ll t, i;
	cin >> t;
	while (t--)
	{


	}


	return 0;
}
