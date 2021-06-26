#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define jaldi_chal  ios_base::sync_with_stdio(0); cin.tie(0);
#define tr(c,i) for(auto i=(c).begin(); i != (c).end(); i++)
#define REP(i,k) for( ll i=0;i<k;i++)
#define REW(i,a,b) for(ll i=a;i<=b;i++)
#define MOD 1000000007
#define F first
#define dbg(x)  cout<<#x<<" " <<x<<endl;
#define S second
#define inf 1e10
#define endl "\n"
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
ll power(ll a, ll b);

char s[1001][1001];




ll   dis[2001][2001];


ll vis[2001][2001];



ll dx[4] = { -1, 0, 1, 0};
ll dy[4] = {0, 1, 0, - 1};

ll n, m;


bool check(ll x, ll y)
{

	if (x < 1 || x > n || y < 1 || y > m) return false;




	return true;

}


void bfs(ll x, ll y)
{





	dis[x][y] = 0;


	deque<pair<ll, ll> > q;
	q.push_back({x, y});


	while (!q.empty())
	{
		ll row = q.front().F;

		ll col = q.front().S;






		ll val = dis[row][col];

		q.pop_front();

		for (ll i = 0; i < 4; i++)
		{
			if (check(row + dx[i], col + dy[i]))
			{
				ll nx = row + dx[i], ny = col + dy[i];

				ll w = (s[nx][ny] != s[row][col]);






				if (val + w < dis[nx][ny])
				{


					dis[nx][ny] = val + w;

					if (w == 1)
					{
						q.push_back({nx, ny});
					}
					else {
						q.push_front({nx, ny});
					}



				}






			}
		}


	}






}









int main() {


	jaldi_chal
	ll t = 1, i;
	cin >> t;
	while (t--)
	{

		cin >> n >> m;





		REW(i, 1, n)
		{
			REW(j, 1, m) cin >> s[i][j], dis[i][j] = inf;




		}






		bfs( 1,  1);


		ll count = 0;


		cout << dis[n][m] << endl;

























	}


	return 0;
}


ll power(ll a, ll b) {
	ll res = 1;
	while (b)
	{
		if (b % 2) b-- , res = res * a;
		else b = b / 2 , a *= a;
	}
	return res;
}