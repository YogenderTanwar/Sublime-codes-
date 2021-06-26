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
vector<int> arr[100005], rg[100005];

int n, m;
int vis1[100005], vis2[100005];


stack<int > s;
int g_no = 0;

vector<int> ans;


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


    for (auto x : rg[node])
    {
        if (!vis2[x]) rev_dfs(x);
    }
}


void ssc()
{
    for (int i = 1; i <= n; i++)
    {
        if (!vis1[i]) fwd_dfs(i);
    }

    while (!s.empty())
    {
        if (!vis2[s.top()]) g_no++, rev_dfs(s.top()), ans.push_back(s.top());

        s.pop();
    }
}



signed   main()
{
    fast
    int t = 1;
    //cin >> t;
    while (t--)
    {
        cin >> n >> m;

        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            arr[u].push_back(v);
            rg[v].push_back(u);

        }

        ssc();

        cout << ans.size() << endl;


        if (ans.size() != 1)
        {
            clr(vis1);
            int a = ans[0], b = ans[1];
            fwd_dfs(a);
            cout << "NO" << endl;
            if (vis1[b] == 1)
            {
                cout << b << " " << a << endl;
            }
            else cout << a << " " << b << endl;




        }
        else
        {
            cout << "YES" << endl;

        }










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



