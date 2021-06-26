#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define MOD 1000000007
const int inf = 1e18;
int power(int a, int b);
int dp[12][110][2]; // pos sum flag
int a[20];

int digi(string s)
{
	int ans = 0;
	for (auto x : s)
	{
		ans += (x - '0');
	}
	return ans;

}

int solve(int pos, int sum, int n, int flag) // flag==0 limit check
{

	if (pos > n) return sum;

	if (dp[pos][sum][flag] != -1) return  dp[pos][sum][flag];

	int limit = 9;
	if (!flag) limit = a[pos];

	int ans = 0;


	for (int i = 0; i <= limit; i++)
	{
		if (flag || i < limit)  ans += (solve(pos + 1, sum + i, n, 1));
		else  ans += (solve(pos + 1, sum + i, n, 0));
	}

	return dp[pos][sum][flag] = ans;

}



signed   main()
{
	fast
	int t = 1;
	string l, r;






	while (1)
	{
		cin >> l >> r;

		if (l == "-1") break;


		memset(dp, -1, sizeof dp);
		for (int i = 1; i <= l.size(); i++)
		{
			a[i] = l[i - 1] - '0';

		}
		int val = (solve(1, 0, l.size(), 0));

		memset(dp, -1, sizeof dp);

		for (int i = 1; i <= r.size(); i++)
		{
			a[i] = r[i - 1] - '0';

		}

		int val_2 = (solve(1, 0, r.size(), 0));

		//cout << val_2 << endl;


		int ans = val_2 - val + digi(l);


		cout << ans << endl;



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







