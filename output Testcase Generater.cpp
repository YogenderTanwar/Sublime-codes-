// output generator file
#include<bits/stdc++.h>
using namespace std;
#define int int64_t

int numberOfTestCaseFiles = 10;


const int maxn = 100005;


int  a[maxn];

int  pre[maxn], suf[maxn];

int  gcd(int  x, int  y)
{
	if (y == 0) return x;
	else return gcd(y, x % y);
}

int  ga, ans;


int32_t main() {
	for (int fileIdx = 1; fileIdx <= 10; ++fileIdx) {
		// freopen("in.txt" , "r" , stdin);
		ifstream fin;
		fin.open("in" + to_string(fileIdx) + ".txt");
		ofstream fout;
		fout.open("out" + to_string(fileIdx) + ".txt" );

		int tt;

		fin >> tt;
		while (tt--)
		{
			int n;
			fin >> n;
			int a[n];
			for (int i = 0; i < n; i++)
			{
				fin >> a[i];
			}
			int m;
			fin >> m;
			int b[m];
			for (int i = 0; i < m; i++)
			{
				fin >> b[i];
			}

			int s1 = 0, s2 = 0, sum = 0;
			int i = 0, j = 0;
			while (i < n && j < m)
			{
				if (a[i] < b[j])
				{
					s1 += a[i++];
				} else {
					if (b[j] < a[i])
					{
						s2 += b[j++];
					} else {
						sum += max(s1, s2) + a[i];
						s1 = 0;
						s2 = 0;
						i++;
						j++;
					}
				}
			}
			while (i < n)
			{
				s1 += a[i++];
			}

			while (j < m)
			{
				s2 += b[j++];
			}

			sum += max(s1, s2);
			fout << sum << "\n";
		}




		// generate the output file


		cout << "File out" << fileIdx << ".txt generated!" << endl;

	}

}