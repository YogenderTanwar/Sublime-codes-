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


int gcd(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

bool find_any_solution(int a, int b, int c, int &x, int &y) {

	int x0 , y0;
	int g = gcd(abs(a), abs(b), x0, y0);
	if (c % g) {
		return false;
	}

	x = x0 * c / g;
	y = y0 * c / g;

	if (a < 0) x = -x;
	if (b < 0) y = -y;
	return true;
}

signed main()
{
	int t , a , b , c , x , y;

	cin >> t;

	while (t--)
	{
		cout << "a : " , cin>>a;

		cout << "b : " , cin>>b;

		cout << "c : " , cin>>c;

		if (find_any_solution(a , b , c , x , y) == false) {
			cout << "No solution exists\n\n";
		}
		else
		{
			cout << "x = " << x << " y = " << y << endl << endl;
		}
	}
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



