#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
ll op1 = LLONG_MAX, op2 = LLONG_MAX;
ll x;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    ll v = (a * b) / gcd(a, b);
    return v;
}
void divisors(ll n)
{
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (lcm(i, n / i) == x)
            {
                if (max(op1, op2) > max(i, n / i))
                {
                    op1 = i;
                    op2 = n / i;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x;
    divisors(x);
    cout << op1 << " " << op2 << "\n";

    return 0;
}