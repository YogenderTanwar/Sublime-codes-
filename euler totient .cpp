#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define jaldi_chal  ios_base::sync_with_stdio(0); cin.tie(0);
#define tr(c,i) for(auto i=(c).begin(); i != (c).end(); i++)
#define REP(i,k) for( ll i=0;i<k;i++)
#define REW(i,a,b) for(ll i=a;i<=b;i++)
#define MOD 1000000007
#define F first
#define dbg(x)  cout<<#x<<" " <<x<<endl;
#define S second
#define inf 1e10
#define endl "\n"
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
ll power(ll a, ll b);

const ll N = 100001;

ll arr[N];

void init() // O(N llog(log(N)))
{
	REW(i, 1, N - 1) arr[i] = i;

	for (ll i = 2; i * i < N; i++)
	{
		if (arr[i] == i)
		{
			for (ll j = i; j < N; j += i)
			{
				arr[j] /= i;
				arr[j] *= (i - 1);

			}
		}
	}

}
ll phi(ll n) // O(sqrt(N))
{
	ll res = n;

	for (ll i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			res /= i;
			res *= (i - 1);
			while (n % i == 0) n = n / i;
		}
	}

	if (n > 1) res /= n, res *= (n - 1);

	return res;
}



int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	jaldi_chal
	ll t = 1, i;
	cin >> t;
	init();
	while (t--)
	{

		ll n;
		cin >> n;


		cout << arr[n] << endl;








	}


	return 0;
}


ll power(ll a, ll b) {
	ll res = 1;
	while (b)
	{
		if (b % 2) b-- , res = res * a;
		else b = b / 2 , a *= a;
	}
	return res;
}