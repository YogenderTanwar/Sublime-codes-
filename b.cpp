#include<bits/stdc++.h>
using namespace std;
#define int long long //delete if causing problems
#define F first
#define S second
#define setbit(n) __builtin_popcountll(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n" //delete if interactive
#define MOD 1000000007
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}
const int inf = 1e18;
int power(int a, int b);


signed   main()
{
    fast
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {

        string s;
        s = "sdjfsa";
        cout << s.substr(1);




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



