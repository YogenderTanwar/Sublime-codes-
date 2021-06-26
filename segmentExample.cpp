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
using namespace std;
using ll = long long;

/*
int comp(int a,int b)
{
	return min(a,b);

}
*/
// SparseTable<int> obj(a,comp);




// 0-based indexing
template<class T>


class SegmentTree
{

public :
	// call  constructor
	SegmentTree(vector<T> data, T value,  T (*combine)(T obj1, T obj2));

	SegmentTree(T ar[], T n, T value, T (*combine)(T obj1, T obj2));

	T query(int  l, int  r);

	void update(T val, int  pos);

private:


	vector<T> stree;

	int  sizeofarray;

	T valueofextra;



	void build(vector<T> data);

	T (*combine)(T obj1, T obj2);

};


template<class T >  SegmentTree<T>::SegmentTree(vector<T> data, T value,   T (*combine)(T obj1, T obj2))
{
	this->combine = combine;
	sizeofarray = (data.size());

	valueofextra = value;
	build(data);

}


template<class T >  SegmentTree<T>::SegmentTree(T ar[], T n, T value,   T (*combine)(T obj1, T obj2))
{
	this->combine = combine;
	sizeofarray = (n);

	vector<T> data;

	for (int  i = 0; i < n; i++) data.push_back(ar[i]);

	valueofextra = value;
	build(data);

}

template<class T> void SegmentTree<T>::build(vector<T> data)
{

	stree.resize(sizeofarray * 2);


	int  n = data.size();

	for (int  i = 0; i < n; i++)
	{
		stree[n + i] = data[i];
	}


	for (int  i = n - 1; i >= 1; i--)
	{
		stree[i] = combine(stree[2 * i], stree[2 * i + 1]);
	}




}


template<class T> T SegmentTree<T>:: query(int  l, int  r) // [l,r) always increase r
{
	l += sizeofarray;
	r += sizeofarray;

	T resl = valueofextra, resr = valueofextra;


	if (l == r) return stree[l];





	while (r > l)
	{

		if (l % 2) resl = combine(resl, stree[l++]);

		if (r % 2) resr = combine(stree[--r], resr);




		l = l / 2;

		r = r / 2;



	}


	return combine(resl, resr);




}

template<class T> void SegmentTree<T>::update(T val, int  pos)
{
	pos += sizeofarray;

	stree[pos] = val;

	while (pos > 1)
	{
		pos = pos / 2;

		stree[pos] = combine(stree[2 * pos], stree[2 * pos + 1]);
	}
}
struct  node
{
	int maxSum;
	int sumofall;
	int prefix, suffix;

	node() {

	}
	node (int val)
	{
		maxSum = sumofall = prefix = suffix = val;

	}


};


node comp(node a, node b)
{
	node *ptr = new node();

	ptr->maxSum = max(a.maxSum, b.maxSum);

	ptr->maxSum = max(ptr->maxSum, a.suffix + b.prefix);

	ptr->sumofall = (a.sumofall + b.sumofall);

	ptr->prefix = max(a.prefix, a.sumofall + b.prefix);

	ptr->suffix = max(b.suffix, b.sumofall + a.suffix);

	return *ptr;
}

signed   main()
{
	fast
	int t = 1;
	//cin >> t;
	while (t--)
	{

		int n, m;
		cin >> n >> m;

		vector<node> a(n);

		for (int i = 0; i < n; i++)
		{
			int ele;
			cin >> ele;
			a[i] = node(ele);


		}

		node identity(0);

		SegmentTree<node> obj(a, identity, comp);


		while (m--)
		{
			int k, x;
			cin >> k >> x;
			k--;

			node z(x);




			obj.update(z, k);

			cout << obj.query(0, n).maxSum << endl;



		}








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



