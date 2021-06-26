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

vector<int> sort_cyclic_shifts(string const& s) {
	int n = s.size();
	const int alphabet = 256;

	vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
	for (int i = 0; i < n; i++)
		cnt[s[i]]++;
	for (int i = 1; i < alphabet; i++)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; i++)
		p[--cnt[s[i]]] = i;
	c[p[0]] = 0;
	int classes = 1;
	for (int i = 1; i < n; i++) {
		if (s[p[i]] != s[p[i - 1]])
			classes++;
		c[p[i]] = classes - 1;
	}

	vector<int> pn(n), cn(n);
	for (int h = 0; (1 << h) < n; ++h) {
		for (int i = 0; i < n; i++) {
			pn[i] = p[i] - (1 << h);
			if (pn[i] < 0)
				pn[i] += n;
		}
		fill(cnt.begin(), cnt.begin() + classes, 0);
		for (int i = 0; i < n; i++)
			cnt[c[pn[i]]]++;
		for (int i = 1; i < classes; i++)
			cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--)
			p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		classes = 1;
		for (int i = 1; i < n; i++) {
			pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
			pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
			if (cur != prev)
				++classes;
			cn[p[i]] = classes - 1;
		}
		c.swap(cn);
	}
	return p;
}

vector<int> suffix_array_construction(string s) {
	s += "#";
	vector<int> sorted_shifts = sort_cyclic_shifts(s);
	sorted_shifts.erase(sorted_shifts.begin());
	return sorted_shifts;
}

vector<int> lcp_construction(string const& s, vector<int> const& p) {

	// LCP[i]=common prefix in i and i-1 suffix in sorted order.
	int n = s.size();
	vector<int> rank(n , 0);
	for (int i = 0; i < n; i++)
		rank[p[i]] = i;

	int h = 0, k;

	vector<int> lcp(n, 0);
	for (int i = 0; i < n; i++) {
		if (rank[i] > 0) {
			k = p[rank[i] - 1];

			while (s[i + h] == s[k + h]) h++;

			lcp[rank[i]] = h;

			if (h > 0) h--;
		}

	}
	return lcp;
}


signed   main()
{
	fast
	int tt = 1;
	//cin >> tt;
	while (tt--)
	{

		string s = "aaaa";

		string rev(s);

		reverse(all(rev));

		string ans = (s + "$" + rev);
		dbg(ans);
		dbg(ans.size());




		vector<int> sa = suffix_array_construction(ans);


		vector<int> lcp = lcp_construction(ans, sa);


		int len = ans.size(), actual_len = s.size();

		int res = 0, start_poistion = -1;
		// longest length palindrome

		for (int i = 0; i < len; i++)
		{
			if (lcp[i] > res)
			{

				if ((sa[i] < actual_len && sa[i - 1] > actual_len) || (sa[i] > actual_len && sa[i - 1] < actual_len))
				{
					res = lcp[i];
					start_poistion = sa[i];


				}

			}
		}


		cout << ans.substr(start_poistion, res) << endl;







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



