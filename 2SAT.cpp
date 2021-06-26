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
vector<int> arr[200005], rg[200005];

int n, m;
int vis1[200005], vis2[200005], comp[200005], ans[100005];




stack<int > s;
int g_no = 0;




void fwd_dfs(int node)
{
	vis1[node] = 1;
	for (auto x : arr[node])
	{
		if (!vis1[x]) fwd_dfs(x);
	}
	s.push(node);
}

void rev_dfs(int node)
{
	vis2[node] = 1;
	//cout << node << " " << g_no << endl;
	comp[node] = g_no;


	for (auto x : rg[node])
	{
		if (!vis2[x]) rev_dfs(x);
	}
}


bool  ssc()
{
	for (int i = 0; i < n; i++)
	{
		if (!vis1[i]) fwd_dfs(i);
	}

	while (!s.empty())
	{
		if (!vis2[s.top()]) g_no++, rev_dfs(s.top());


		s.pop();
	}

	for (int i = 0; i < n; i += 2) {
		if (comp[i] == comp[i + 1])
			return false;
		//cout << comp[i] << " " << comp[i + 1] << endl;

		ans[i / 2] = comp[i] > comp[i + 1];
	}
	return true;

}



signed   main()
{
	fast
	int t = 1;
	//cin >> t;
	while (t--)
	{
		cin >> m >> n;
		n = 2 * n;


		// 2*k ans 2*k+1 are p and negation of p

		for (int i = 1; i <= m; i++)
		{
			int u, v;
			char x, y;

			string a, b, c, d;

			cin >> a >> b >> c >> d;


			x = a[0];
			y = c[0];
			u = b[0] - '0';
			v = d[0] - '0';
			u--;
			v--;









			if (x == '+' && y == '+')
			{
				arr[2 * u + 1].push_back(2 * v);
				arr[2 * v + 1].push_back(2 * u);
				rg[2 * v].push_back(2 * u + 1);
				rg[2 * u].push_back(2 * v + 1);

			}
			else if (x == '+' && y == '-')
			{
				arr[2 * u + 1].push_back(2 * v + 1);
				arr[2 * v].push_back(2 * u);
				rg[2 * v + 1].push_back(2 * u + 1);
				rg[2 * u].push_back(2 * v);
			}
			else if (x == '-' && y == '+')
			{
				arr[2 * u].push_back(2 * v);
				arr[2 * v + 1].push_back(2 * u + 1);
				rg[2 * v].push_back(2 * u);
				rg[2 * u + 1].push_back(2 * v + 1);
			}
			else {
				arr[2 * u].push_back(2 * v + 1);
				arr[2 * v].push_back(2 * u + 1);
				rg[2 * v + 1].push_back(2 * u);
				rg[2 * u + 1].push_back(2 * v);

			}

		}

		if (ssc())
		{
			for (int i = 0; i < n; i += 2) {

				if (ans[i / 2] ) cout << "+" << " ";
				else cout << "-" << " ";


			}

		}
		else cout << "IMPOSSIBLE" << endl;

















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



