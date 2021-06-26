#include<bits/stdc++.h>
using namespace std;
#define int long long //delete if causing problems
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n" //delete if interactive
#define MOD 1000000007
const int inf = 1e18;
int power(int a, int b);
const int N = 26;

// struct trie {

// 	struct trie *children[N];

// 	bool flag = false; // end  of word;


// };



struct trie {

	struct trie *children[N];

	bool flag = false; // end  of word;

	trie ()
	{
		for (int i = 0; i < N; i++)
		{
			this->children[i] = NULL;
		}

		this->flag = false;

	}

	// no need of get_node function and can access trie *p= new trie()




};




// struct trie *get_node()
// {
// 	struct trie *temp = new trie;

// 	for (int i = 0; i < N; i++)
// 	{
// 		temp->children[i] = NULL;
// 	}

// 	temp->flag = false;


// 	return temp;
// };

void insert(trie * root , string key)
{
	trie * p = root;

	for (int i = 0; i < key.size(); i++)
	{
		if (!p->children[key[i] - 'a'])
		{
			p->children[key[i] - 'a'] = new trie();
		}
		p = p->children[key[i] - 'a'];

	}

	p->flag = true;
}


bool search(struct trie *root, string key)
{
	struct trie *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl != NULL && pCrawl->flag);
}





signed   main()
{
	fast
	int z = 1;
	//cin >> z;

	for (int tt = 1; tt <= z; tt++)
	{



		struct trie *root = new trie();






		//cout << "Case #" << tt << ": " << endl;  // ans


	}
	return 0;
}

int power(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b % 2) b-- , res = res * a;
		else b = b / 2 , a *= a;
	}
	return res;
}

/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/



