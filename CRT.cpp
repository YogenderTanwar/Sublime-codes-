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

int modInverse(int a, int m)
{
	int m0 = m;
	int y = 0, x = 1;

	if (m == 1)
		return 0;

	while (a > 1) {
		// q is quotient
		int q = a / m;
		int t = m;

		// m is remainder now, process same as
		// Euclid's algo
		m = a % m, a = t;
		t = y;

		// Update y and x
		y = x - q * y;
		x = t;
	}

	// Make x positive
	if (x < 0)
		x += m0;

	return x;
}

int crt(vector<pair<int, int> > v) // {(2,1), (3,2) , (7,4)};
{
	int ans = 0;
	int n = v.size();
	int m = 1;

	for (int i = 0; i < n; i++)
	{
		m *= (v[i].first);

	}

	for (int i = 0; i < n; i++)
	{
		int t = 1;

		for (int j = 0; j < i; j++)
		{
			t *= (v[j].first);
			t *= modInverse(v[j].first, v[i].first);
			t %= m;


		}

		// x%pi=ki

		// x1+x2p1 + x3p1p2 .. .. xip1p2.. p(i-1) +0 +0 .. .=ki %pi

		// ans+ xip1p2...p(i-1)=ki )%pi
		//  xi=(ki-ans)*(p1)-1....p(i-1)-1



		ans += (t * (v[i].second - ans + m)) % m;
	}

	return ans;

}


signed   main()
{
	fast
	int t = 1;
	//cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		vector<pair<int, int> > v(n);


		for (int i = 0; i < n; i++)
		{
			cin >> v[i].first >> v[i].second;

		}

		cout << crt(v) << endl;





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



