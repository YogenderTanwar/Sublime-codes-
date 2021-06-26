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


int binpow(int a, int n, int mod)
{

	int res = 1;
	while (n > 0)
	{
		if (n % 2)
		{
			res = (mulmod(res, a, mod)) ;
			n--;
		}
		else {
			a = mulmod(a, a, mod);
			n = n / 2;

		}

	}

	return res % mod;

}



bool isprime(int n, int iteration = 5 )
{
	if (n <= 4) return n == 3 || n == 2;

	for (int i = 1; i <= iteration; i++)
	{
		int a = (2 + rand() % (n - 3));
		int res = (binpow(a, n - 1, n));
		//dbg(res);


		if (res != 1) return false;
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

		if (isprime(n)) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	return 0;
}


/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/



