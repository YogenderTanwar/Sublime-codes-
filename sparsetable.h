#ifndef SPARSETABLE_H
#define SPARSETABLE_H
#include <vector>
#include <math.h>
using namespace std;
using ll = long long;

/*
int comp(int a,int b)
{
	return min(a,b);

}
*/
// SparseTable<int> obj(a,comp);


template<class T>

class SparseTable
{
public:

	//call constructor
	SparseTable(vector<T> data,  T (*combine)(T obj1, T obj2));

	SparseTable(T ar[], T n, T (*combine)(T obj1, T obj2));

	T query(ll l , ll r);

private:

	vector<vector<T>> sp;


	void build(vector<T> data);

	ll maxN;

	T (*combine)(T obj1, T obj2);





};


template<class T> SparseTable<T>::SparseTable(vector<T> data,  T (*combine)(T obj1, T obj2) )
{
	this->combine = combine;
	maxN = log2(data.size()) + 1;

	build(data);




}

template<class T> SparseTable<T>::SparseTable(T ar[], T n,  T (*combine)(T obj1, T obj2) )
{
	this->combine = combine;
	maxN = log2(n) + 1;

	vector<T> data;

	for (ll i = 0; i < n; i++) data.push_back(ar[i]);
	build(data);
}


template<class T> void SparseTable<T>::build(vector<T>  data)
{
	ll n = data.size();
	sp.resize(n, vector<T>(maxN));



	for (ll i = 0; i < n; i++) sp[i][0] = data[i];


	for (ll j = 1; (1 << j) <= n; j++)
	{
		for (ll i = 0; i + (1 << j) - 1 < n; i++)
		{
			sp[i][j] = combine(sp[i][j - 1] , sp[i + (1 << j - 1)][j - 1]);
		}
	}
}


template<class T> T SparseTable<T>::query(ll l, ll r)
{
	ll diff = (r - l + 1);

	diff = log2(diff);


	ll x = (r - (1 << diff) + 1);

	return  combine(sp[l][diff], sp[x][diff]);

}

#endif