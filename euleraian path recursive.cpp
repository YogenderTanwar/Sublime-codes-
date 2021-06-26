#include <bits/stdc++.h>
#define dbg(x)  cout<<#x<<" "<<x<<endl;

using namespace std;

int n, k;
int cur[26];
vector<int> path;
// eulerain path recursive

void dfs(int v) {
	dbg(v);

	while (cur[v] < k) {
		int u = cur[v]++;
		dfs(u);
		path.push_back(u);
	}
}

int main() {
	scanf("%d%d", &n, &k);
	dfs(0);
	printf("a");

	for (auto x : path ) cout << x << " ";
	cout << endl;
	for (int i = 0; i < n - 1; ++i)
		printf("%c", path[i % path.size()] + 'a');
}