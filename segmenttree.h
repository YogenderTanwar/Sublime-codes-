#ifndef SEGMENTTRE_H
#define SEGMENTTRE_H
#include <vector>
#include <math.h>
using namespace std;


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

#endif