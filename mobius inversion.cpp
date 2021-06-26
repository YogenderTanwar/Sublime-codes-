#include<bits/stdc++.h>
using namespace std;
#define int long long //delete if causing problems
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n" //delete if interactive
#define MOD 1000000007
const int inf = 1e18;
int power(int a, int b);

const int N = 1000001; // change accor. to prob
int lp[N + 1]; // least prime no
vector<int> pr;
int phi[N], mob[N];


void linear_sieve(int n)
{
	phi[1] = 1;
	mob[1] = 1;

	for (int i = 2; i <= n; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back (i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= n; ++j)
			lp[i * pr[j]] = pr[j];

		int x = i;

		int res = i;
		int ans = 1;
		int cnt = 0;

		if (lp[i] == i)
		{
			phi[i] = i - 1;
			mob[i] = -1;
			continue;


		}



		while (x > 1)
		{
			int d = lp[x];
			int k = 0;


			while (x % d == 0)
			{
				res -= (res / d);
				x = x / d;
				k++;

				if (k > 1) ans = 0;



			}
			cnt++;
		}

		if (cnt & 1) ans *= -1;
		else ans *= 1;

		phi[i] = res;
		mob[i] = ans;

	}

}






signed   main()
{
	fast
	int t = 1;
	cin >> t;



	linear_sieve(1000000);

	while (t--)
	{
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;

		int ans = 0;

		for (int i = 1; i <= min(b / k, d / k); i++)
		{
			ans += (mob[i] * (b / k / i) * (d / k / i));
			//cout << i << " " << (mob[i] * (b / i) * (d / i)) << endl;

		}

		int y = 0;
		int m = min(b, d);
		b = m;
		d = m;


		for (int i = 1; i <= min(b / k, d / k); i++)
		{
			y += (mob[i] * (b / k / i) * (d / k / i));
			//cout << i << " " << (mob[i] * (b / i) * (d / i)) << endl;

		}

		cout << ans - (y - 1) / 2;















	}
	return 0;
}

int power(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b % 2) b-- , res = res * a;
		else b = b / 2 , a *= a;
	}
	return res;
}

/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/



