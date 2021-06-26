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

//  Referance :- https://codeforces.com/blog/entry/44351
vector<int> arr[100005];
int ans[100005];
int cnt[100005];
int sz[100005];
int big[100005];
int curr = 0, maxx = 0;
int col[100005];

void solve(int node, int par) {
    sz[node] = 1;
    for (auto child : arr[node]) {
        if (child == par) continue;
        solve(child, node);
        sz[node] += sz[child];

    }
}



void add(int v, int p, int x) {
    cnt[ col[v] ] += x;
    for (auto u : arr[v])
        if (u != p && !big[u])
            add(u, v, x);
}



void dfs(int node, int par, bool keep) {

    int mx = -1, bigChild = -1;
    for (auto x : arr[node]) {
        if (x != par) {
            if (sz[x] > mx) mx = sz[x], bigChild = x;
        }

    }
    for (auto x : arr[node]) {
        if (x != par && x != bigChild) {
            dfs(x, node, 0); // run a dfs on small childs and clear them from cnt
        }
    }

    if (bigChild != -1) dfs(bigChild, node, 1), big[bigChild] = 1; // bigChild marked as big and not cleared from cnt

    add(node, par, 1);
    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.

    ans[node] = curr;

    if (bigChild != -1) big[bigChild] = 0;
    if (keep == 0)
        add(node, par, -1);


}



signed   main()
{
    fast
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> col[i];
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            arr[u].push_back(v);
            arr[v].push_back(u);


        }


        solve(1, -1);
        dfs(1, -1, 1);

        for (int i = 1; i <= n; i++) cout << ans[i] << " ";







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



