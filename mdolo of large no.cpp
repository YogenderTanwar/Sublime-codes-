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
		string s;
		cin >> s;

		int a, b;
		cin >> a >> b;
		int n = s.size();


		vector<int> pre(n, 0), suff(n, 0);

		pre[0] = (s[0] - '0') % a;
		int p = 1;

		suff[n - 1] = (s[n - 1] - '0') % b;



		for (int i = 1; i < n; i++)
		{
			p = (p * 10) % a;
			pre[i] = (s[i] - '0' + 10 * pre[i - 1]) % a;

		}
		p = 1;

		for (int i = n - 2; i >= 0; i--)
		{
			p = (p * 10) % b;
			suff[i] = ((s[i] - '0') * p + suff[i + 1]) % b;
		}

		for (int i = 0; i < n - 1; i++)
		{
			//cout << pre[i] << " " << suff[i + 1] << endl;

			if (pre[i] == 0 && suff[i + 1] == 0 && s[i + 1] != '0')
			{
				cout << "YES" << endl;
				cout << s.substr(0, i + 1) << endl;
				cout << s.substr(i + 1, (n - i - 1));
				return 0;

			}
		}

		cout << "NO" << endl;













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



