#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string str;
	cin >> str;
	int len = str.size();
	str += str;
	int ans = 0; //assumed min string starting index
	int next = 1; //the new string to be checked ie compared with our string starting at ans
	int matchlen = 0;
	while (next <= str.size() / 2 and next + matchlen < str.size())
	{
		int old = ans + matchlen;
		int neww = next + matchlen;
		if (str[old] == str[neww])
		{
			matchlen++;

		}
		else if (str[neww] < str[old])
		{
			//i found a better answer it means i must have encountered a lesser character at neww
			if (str[neww] < str[next])
				ans = neww;
			else
				ans = next;
			//cout<<neww<<endl;
			next = neww + 1;
			matchlen = 0;
		}
		else
		{	//str[neww]> str[old]
			next = next + matchlen + 1;
			matchlen = 0;


		}
	}

//str+=str;

	cout << str.substr(ans, len);

}