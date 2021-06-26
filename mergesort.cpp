#include<iostream>
using namespace std;

void merge(int *a, int s, int e)
{
	int temp[100];

	int mid = (s + e) / 2;

	int i = s, j = mid + 1, k = s;

	while (i <= mid && j <= e)
	{
		if (a[i] < a[j]) temp[k++] = a[i++];
		else temp[k++] = a[j++];
	}

	while (i <= mid) temp[k++] = a[i++];

	while (j <= e) temp[k++] = a[j++];


	for (int i = s; i <= e; i++)
	{
		a[i] = temp[i];
	}





}


void mergesort(int *a , int s, int e)
{

	if (s >= e) return;

	int mid = (s + e) / 2;

	mergesort(a, s, mid);
	mergesort(a, mid + 1, e);

	merge(a, s, e);


}

int main()
{

	int a[100];

	int n;

	cin >> n;


	for (int i = 1; i <= n; i++) cin >> a[i];

	mergesort(a, 1, n);


	for (int i = 1; i <= n; i++) cout << a[i] << " ";



}