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

vector<int > bit;
int  n, q;
const int maxN = 1000010;


void update(int  index, int  val)
{

	while (index > 0 && index <= maxN)
	{
		//cout << index << " ";
		bit[index] += val;
		index = index + (index & (-index));

	}
}

int  sum(int  index)
{
	int  val = 0;
	while (index > 0)
	{


		val += bit[index];
		index -= (index & (-index));

	}

	return val;

}
int a[maxN], rem[maxN], cnt[maxN], sz, tot[maxN];




signed   main()
{
	fast
	int t = 1;
	//cin >> t;
	while (t--)
	{

		bit.resize(maxN);

		cin >> n;

		for (int i = 1; i <= n; i ++) cin >> a[i], tot[sz++] = a[i];

		sort(tot, tot + sz);
		sz = unique(tot, tot + sz) - tot;


		for (int i = 1; i <= n; i ++) {
			a[i] = lower_bound(tot, tot + sz, a[i]) - tot;
			//dbg(a[i]);

		}
		for (int i = n; i >= 1; i--)
		{
			cnt[a[i]]++;
			update(cnt[a[i]], 1);
			rem[i] = cnt[a[i]];
		}

		int ans = 0;

		clr(cnt);

		//cout << sum(1);



		for (int i = 1; i <= n; i++)
		{

			//cout << rem[i] << " ";


			cnt[a[i]]++;
			update(rem[i], -1);

			//dbg(sum(cnt[a[i]] - 1));


			ans += sum(cnt[a[i]] - 1);


		}

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

/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/



