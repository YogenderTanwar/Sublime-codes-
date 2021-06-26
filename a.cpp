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
const int N = 2000006;

const int M2 =  998244353;
const int M1 =  1000000007;

int Hash[2000002];
int p[2000002];

// 1 indexed based hashing faster than double hashing
int mpow(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1)
			r = (r * a) % M1;
		a = (a * a) % M1;
		b >>= 1;
	}
	return r;
}

int get(int l , int r) {
	return ((Hash[r] - Hash[l - 1] + M1) * p[l - 1]) % M1;
}
signed   main()
{
	fast
	int t = 1;
	//cin >> t;
	while (t--)
	{
		string s;
		cin >> s;


		s += s;
		int n = s.size();
		int x = 1;
		for (int i = 0; i < n; i++) {
			p[i] = mpow(x, M1 - 2);
			x *= 131;
			x %= M1;
		}
		x = 1;
		for (int i = 0; i < n; i++) {
			Hash[i + 1] = (Hash[i] + x * (s[i] - 'a')) % M1;
			x *= 131;
			x %= M1;
		}

		int k = 1;
		n >>= 1;

		for (int i = 2; i <= n; i++) {

			int l = 0, r = n - 1;

			int index = 0;

			while (r >= l) {
				int mid = (l + r) / 2;
				if (get(k, k + mid) == get(i, i + mid)) index = mid + 1, l = mid + 1;
				else r = mid - 1;
			}
			if (index <= n - 1)
				if (s[i + index - 1] < s[k + index - 1]) k = i;
		}

		cout << s.substr(k - 1, n) << endl;



















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



