#include<stdio>
using namespace std;
// #define int long long //delete if causing problems
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n" //delete if interactive
#define MOD 1000000007
// const int inf = 1e18;
int power(int a, int b);

void m(int *p)
{
	for (int i = 0; i < 4; i++) cout << p[i] << " ";


}

signed   main()
{
	fast
	int t = 1;
	//cin >> t;
	while (t--)
	{
		int a[5] = {0, 2, 5};

		m(a);

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



