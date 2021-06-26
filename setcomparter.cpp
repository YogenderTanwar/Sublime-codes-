
// C++17 only

#include <iostream>
#include <string>
#include <set>
using namespace std;

bool lexical_compare(int a, int b) {
	return to_string(a) < to_string(b);
};

int main() {
	set<int, decltype(&lexical_compare)> s(&lexical_compare);

	s.insert(1);
	s.insert(10);
	s.insert(11);
	s.insert(100);

	for (int x : s)
		cout << x << ' ';

	return 0;
}