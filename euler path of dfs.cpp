#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define MOD 1000000007
const ll inf = 1e18;



struct fenwick
{
  ll ft[400005];
  void update(ll i, ll delta)
  {
    while (i <= 400000)
    {
      ft[i] += delta;
      i += (i & (-i));


    }
  }
  ll query(ll i)
  {
    ll sum = 0;
    while (i > 0)
    {
      sum += ft[i];
      i -= (i & (-i));
    }
    return sum;
  }

} fen;


ll power(ll a, ll b);
vector<ll> arr[200004];
ll in[200004], out[200004], ft[400004], val[200004];
ll timer = 1;

void dfs(ll node, ll par)
{
  in[node] = timer;
  ft[timer] = node;
  timer++;
  for (auto x : arr[node])
  {
    if (x == par) continue;
    dfs(x, node);
  }

  out[node] = timer;
  ft[timer] = node;
  timer++;

}






int main()
{
  fast
  ll t = 1;
  //cin >> t;
  while (t--)
  {
    ll n, q;
    cin >> n >> q;
    for (ll i = 1; i <= n; i++) cin >> val[i];

    for (ll i = 1; i < n; i++)
    {
      ll u, v;
      cin >> u >> v;
      arr[u].push_back(v), arr[v].push_back(u);

    }

    dfs(1, -1);

    for (ll i = 1; i <= n; i++) {
      fen.update(in[i], val[i]);
      fen.update(out[i], val[i]);


    }



    while (q--)
    {
      ll type;
      cin >> type;

      if (type == 1)
      {
        ll node, delta;
        cin >> node >> delta;

        fen.update(in[node], delta - val[node]);
        fen.update(out[node], delta - val[node]);
        val[node] = delta;




      }
      else {
        ll node;
        cin >> node;

        cout << (fen.query(out[node]) - fen.query(in[node] - 1)) / 2 << endl;




      }
    }














  }
  return 0;
}

ll power(ll a, ll b)
{
  ll res = 1;
  while (b)
  {
    if (b % 2) b-- , res = res * a;
    else b = b / 2 , a *= a;
  }
  return res;
}
