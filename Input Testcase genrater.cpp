// Input generator file
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int numberOfTestCaseFiles = 10;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	// os<<"[";
	for (int i = 0; i < v.size(); ++i) {
		// if (i) os << ", ";
		os << v[i] << " ";
	}
	// os << "]\n";
	return os;
}
int random(int folds = 1) {
	if (!folds) return 1;
	return rand() * random(folds - 1);
}
int genInt(int s, int e) {  // [s , e)
	int range = (e - s);
	int folds = 1, crange = 1;
	while (crange < range && crange < (LONG_MAX / RAND_MAX)) {
		++folds;
		crange *= RAND_MAX;
	}
	int val = random(folds) % range;
	return val + s;
}

int32_t main() {
	srand(time(0));
	for (int fileIdx = 1; fileIdx <= 10; ++fileIdx) {
		// freopen("in.txt" , "r" , stdin);
		ofstream fout;
		fout.open("in" + to_string(fileIdx) + ".txt");

		// generate an int
		int tt = 10;
		fout << tt << endl;

		while (tt--)
		{
			int n1 = genInt(1, 10000);
			fout << n1 << " ";

			for (int i = 1; i <= n1; i++)
			{
				fout << genInt(-10000, 10000) << " ";

			}
			fout << endl;
			n1 = genInt(1, 10000);
			fout << n1 << " ";
			for (int i = 1; i <= n1; i++)
			{
				fout << genInt(-10000, 10000) << " ";

			}
			fout << endl;





		}

		cout << "File in" << fileIdx << ".txt generated!" << endl;
	}
}

