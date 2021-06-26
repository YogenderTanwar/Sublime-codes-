#include<bits/stdc++.h>
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
const int inf = 1e18;
int power(int a, int b);
struct  group
{
	int l, r, id;


} queries[100005];

int a[100005];

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

unordered_map<int   , int, custom_hash> cnt;

int ans[100005], currans = 0, blocksize;

bool comp(group a, group b)
{
	if (a.l / blocksize != b.l / blocksize) return a.l / blocksize < b.l / blocksize;

	return a.r < b.r;

}

/*
bool operator < (const query &rhs) const {
		if(rhs.l / block_Size != l / block_Size)
			return l < rhs.l;

		return r < rhs.r;
	}
*/

void add(int x)
{
	// dbg(x);

	x = a[x];


	cnt[x]++;

	if (cnt[x] == x)  currans++;

	if (cnt[x] == x + 1) currans--;

}

void remove(int x)
{
	x = a[x];

	cnt[x]--;

	if (cnt[x] == x - 1) currans--;

	if (cnt[x] == x) currans++;


}





signed   main()
{
	fast
	int t = 1;
	//cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		blocksize = sqrt(n);


		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		for (int i = 0; i < m; i++)
		{

			cin >> queries[i].l >> queries[i].r;
			queries[i].id = i;
			queries[i].l--;
			queries[i].r--;

		}

		sort(queries, queries + m, comp);

		int currl = 0, currr = -1;

		for (int i = 0; i < m; i++)
		{
			int l = queries[i].l;
			int r = queries[i].r;

			// cout << l << " " << r << endl;


			while (currl > l) add(--currl);
			while (r > currr) add(++currr);

			while (l > currl) remove(currl++);

			while (r < currr) remove(currr--);

			// dbg(currans);


			ans[queries[i].id] = currans;




		}

		for (int i = 0; i < m; i++) cout << ans[i] << endl;













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



