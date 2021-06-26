#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define jaldi_chal_bsdk  ios_base::sync_with_stdio(false);
#define vll(v)  vector<ll>v;
#define pb(n)   push_back(n);
#define f(i,k)  for(i=1;i<=k;i++)

bool check_power(int n)
{
	if (n == 0)
		return 0;
	while (n != 1)
	{
		if (n % 2 != 0)
			return 0;
		n = n / 2;
	}
	return 1;
}

int main()
{
	jaldi_chal_bsdk;
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll i;
		ll a[n + 1];

		if (check_power(n) == 1)
		{
			cout << "-1" << endl;
		}
		else
		{
			ll temp = 0, temp1 = 0;
			for (i = 1; i <= n; i++) { a[i] = i; }

			for (i = 1; i <= n; )
			{
				if (a[i] == 1 && check_power(a[i + 1]) == 1)
				{
					temp = a[i];
					a[i] = a[i + 1];
					a[i + 1] = temp;
					temp = a[i + 1];
					a[i + 1] = a[i + 2];
					a[i + 2] = temp;
					i += 3;
				}
				else if (check_power(a[i]) == 1)
				{
					temp1 = a[i];
					a[i] = a[i + 1];
					a[i + 1] = temp1;
					i += 2;
				}
				else
				{
					i++;
				}

			}
			for (i = 1; i <= n; i++)
			{
				cout << a[i] << " ";
			}
			cout << endl;


		}



	}

	return 0;
}