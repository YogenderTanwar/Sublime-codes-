#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define jaldi_chal  ios_base::sync_with_stdio(0); cin.tie(0);
#define tr(c,i) for(auto i=(c).begin(); i != (c).end(); i++)
#define REP(i,k) for( ll i=0;i<k;i++)
#define REW(i,a,b) for(ll i=a;i<=b;i++)
#define M 1000000007
#define F first
#define dbg(x)  cout<<#x<<" " <<x<<endl;
#define S second
#define inf 1e18
#define endl "\n"
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
int  power(int  a, int  b);
const int maxN = 501;

char s[maxN][maxN];
int  vis[maxN][maxN];
int  dis[maxN][maxN];
int  dx[4] = { -1, 0, 1, 0};
int  dy[4] = {0, 1, 0, - 1};
int  n;

bool check(int  x, int  y)
{

	if (x < 1 || x > n || y < 1 || y > n) return false;

	if (vis[x][y] || s[x][y] == 'T') return false;

	return true;

}

void bfs(int  sx, int  sy)
{

	queue<pair<int , int > > q;
	q.push({sx, sy});
	vis[sx][sy] = 1;

	while (!q.empty())
	{
		int  currx = q.front().F;
		int  curry = q.front().S;
		q.pop();

		for (int  i = 0; i < 4; i++)
		{
			if (check(currx + dx[i], curry + dy[i]))
			{
				//cout << "heint o " << endl;
				int  nx = currx + dx[i], ny = curry + dy[i];
				dis[nx][ny] = dis[currx][curry] + 1;
				vis[nx][ny] = 1;

				q.push({nx, ny});

			}
		}
	}

}





signed  main() {


	jaldi_chal
	int  t = 1, i;
	//cin >> t;
	while (t--)
	{

		cin >> n;



		int  sx, sy;
		int  ex, ey;

		for (int  i = 1; i <= n; i++)
		{
			for (int  j = 1; j <= n; j++)
			{
				cin >> s[i][j];
				if (s[i][j] == 'S') sx = i , sy = j;
				if (s[i][j] == 'E') ex = i , ey = j;

			}

		}


		bfs(sx, sy);

		// for (int  i = 1; i <= n; i++)
		// {
		// 	for (int  j = 1; j <= n; j++)
		// 	{
		// 		cout << dis[i][j]  << " ";
		// 	}
		// 	cout << endl;

		// }


		cout << dis[ex][ey];







	}


	return 0;
}


int  power(int  a, int  b) {
	int  res = 1;
	while (b)
	{
		if (b % 2) b-- , res = res * a;
		else b = b / 2 , a *= a;
	}
	return res;
}