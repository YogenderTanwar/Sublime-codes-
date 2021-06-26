#include<bits/stdc++.h>
using namespace std;
using ll = long long ;




int main()
{

	vector<ll> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 };

	vector<ll> ans(v.size(), 0);

	ll len = 1;

	ans[0] = v[0];



	for (ll i = 1; i < v.size(); i++)
	{
		if (v[i] < ans[0]) ans[0] = v[i];

		else if (v[i] > ans[len - 1])
		{
			ans[len++] = v[i];

		}
		else {

			ll index = upper_bound(ans.begin(), ans.begin() + len, v[i]) - ans.begin();
			//cout << index << " " << "hello" << " " << v[i] << endl;

			ans[index] = v[i];

		}
	}





	cout << len << endl;

	return 0;

}