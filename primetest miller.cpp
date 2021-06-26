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

// 100 percent accuracy

int mulmod(int a, int b, int c)
{
	int x = 0, y = a % c;

	while (b > 0)
	{
		if (b % 2)
		{
			x = (x + y) % c;

		}

		y = (y * 2ll) % c;
		b = b / 2;

	}

	return x % c;
}

int  binpower(int  base, int  e, int  mod) {
	int  result = 1;
	base %= mod;
	while (e) {
		if (e & 1)
			result = mulmod(result, base, mod);

		base = mulmod(base, base , mod);
		e >>= 1;
	}
	return result % mod;
}

bool check_composite(int  n, int  a, int  d, int s) {
	int  x = binpower(a, d, n);
	if (x == 1 || x == n - 1)
		return false;
	for (int r = 1; r < s; r++) {
		x = mulmod(x, x, n);
		if (x == n - 1)
			return false;
	}
	return true;
};

bool MillerRabin(int  n) { // returns true if n is prime, else returns false.
	if (n < 2)
		return false;

	int r = 0;
	int  d = n - 1;
	while ((d & 1) == 0) {
		d >>= 1;
		r++;
	}

	for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (n == a)
			return true;
		if (check_composite(n, a, d, r))
			return false;
	}
	return true;
}


signed   main()
{
	fast
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		if (MillerRabin(n)) cout << "YES" << endl;
		else cout << "NO" << endl;





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



