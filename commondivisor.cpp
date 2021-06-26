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


signed   main()
{
	fast
	int t = 1;
	//cin >> t;
	while (t--)
	{
		int n, q;
		cin >> n >> q;


		map<int, int> m;

		int tot = 1;



		for (int i = 2; i * i <= n; i++)
		{
			int cnt = 0;
			while (n % i == 0) cnt++, n = n / i;

			if (cnt > 0) m[i] = cnt;
			tot *= (cnt + 1);


		}
		if (n > 1) m[n] = 1, tot *= 2;

		map<int, int> temp;


		while (q--)
		{
			int type;
			cin >> type;
			int k;
			cin >> k;

			if (type == 1)
			{


				int ans = 1;


				for (auto x : m)
				{
					int cnt = 0;
					while (k % x.F == 0) cnt++, k = k / x.F;

					if (cnt > 0) ans *= (min(cnt + 1, x.S + 1));
				}

				cout << ans << endl;


			}
			else {

				int com = 0;
				temp.clear();

				for (auto x : m)
				{
					int cnt = 0;
					while (k % x.F == 0) cnt++, k = k / x.F;

					if (cnt > 0) temp[x.F] = cnt;

				}
				int ans = 1;

				if (k > 1)  ans = 0;





				for (auto x : m)
				{
					int val = (x.S - temp[x.F] + 1);
					if (val < 0) ans = 0;
					ans *= val;
				}

				if (type == 2) cout << ans << endl;
				else cout << tot - ans << endl;








			}
		}







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



