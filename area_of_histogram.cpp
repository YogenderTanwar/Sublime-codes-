#include<bits/stdc++.h>
using namespace std;
int a[100001];

int solve(int a[], int n)
{
	stack<int> s;
	//for (int i = 0; i < n; i++) cout << a[i] << " ";


	// s.push(a[0]);
	int ans = 0;
	int i = 0;
	while (i < n)
	{
		if (s.empty() || a[s.top()] <= a[i])
		{
			s.push(i++);
		}
		else {

			int val = a[s.top()];
			s.pop();



			if (s.empty())
			{
				ans = max(ans, val * (i));
			}
			else {
				ans = max(ans, val * (i - s.top() - 1));
			}
			//s.push(i);

			//cout << ans << " " << val << endl;
			//i++;

		}









	}

	while (!s.empty())
	{
		int val = a[s.top()];
		s.pop();



		if (s.empty())
		{
			ans = max(ans, val * (i));
		}
		else {
			ans = max(ans, val * (i - s.top() - 1));
		}

	}

	return ans;





}



int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

	}

	cout << solve(a, n);

}