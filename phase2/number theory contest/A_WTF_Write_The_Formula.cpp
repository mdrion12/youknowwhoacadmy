#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    int v = (a * b) / gcd(a, b);
    return v;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v = 1;
    for (int i = 2; i <= 10; i++)
    {
        v = lcm(v, i);
    }
    ll n;
    cin >> n;
    cout << 1ll * (n / v) << "\n";
    return 0;
}