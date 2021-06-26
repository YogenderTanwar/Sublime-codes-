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
const int N = 1501;

int  A1 = 97266353, B1 = 972663749;
int  A2 = 97336357, B2 = 1000000007;

int  inv1 = 475228407;
int  inv2 = 273386266;
int  mp1[N], mp2[N];

int   h1[N], h2[N];
int   p1[N], p2[N];

void build(string arr) {

	p1[0] = p2[0] = 1;

	for (int i = 1; i < N; ++i) {
		p1[i] = (p1[i - 1] * A1) % B1;
		p2[i] = (p2[i - 1] * A2) % B2;
	}

	for (int i = 0; i < arr.size(); ++i) {
		h1[i] = (1LL * arr[i] * p1[i]) % B1;
		h2[i] = (1LL * arr[i] * p2[i]) % B2;

		if (i) {
			h1[i] = (h1[i] + h1[i - 1]) % B1;
			h2[i] = (h2[i] + h2[i - 1]) % B2;
		}
	}

	mp1[0] = mp2[0] = 1;
	for (int i = 1; i < N; ++i) {
		mp1[i] = (mp1[i - 1] * inv1) % B1;
		mp2[i] = (mp2[i - 1] * inv2) % B2;
	}
}

pair<int , int > get_Hash(int a, int b) {
	pair<int , int > out = {h1[b], h2[b]};

	if (a) {
		out.first =  (((h1[b] - h1[a - 1]) % B1) + B1) % B1;
		out.second = (((h2[b] - h2[a - 1]) % B2) + B2) % B2;

		out.first =  (out.first *  mp1[a]) % B1;
		out.second = (out.second * mp2[a]) % B2;
	}

	return out;
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

		string c;
		cin >> c;

		int k;
		cin >> k;





		int n = s.size();

		vector<vector<int>> a(n, vector<int>(26, 0));


		build(s);

		vector<pair<int, int> > hashes;



		int count = 0;


		for (int i = 0; i < n; i++)
		{
			int curr = 0;

			for (int j = i; j < n; j++)
			{
				if (c[s[j] - 'a'] == '0' && curr == k) break;
				if (c[s[j] - 'a'] == '0') curr++;

				count++;
				hashes.push_back(get_Hash(i, j));
			}



		}


		int ans = 0;



		sort(hashes.begin(), hashes.end());

		while (hashes.size()) {

			while (hashes.size() > 1 && hashes[hashes.size() - 1] == hashes[hashes.size() - 2]) hashes.pop_back();

			//cout << hashes.back().F << " " << hashes.back().S << endl;

			++ans; hashes.pop_back();
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



