#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Simple primality test (deterministic for n < 1e9)
bool is_prime(ll x)
{
    if (x < 2)
        return false;
    for (ll i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    if (is_prime(n))
    {

        cout << 1 << "\n"
             << n << "\n";
    }
    else if (is_prime(n - 2))
    {

        cout << 2 << "\n"
             << 2 << " " << (n - 2) << "\n";
    }
    else
    {

        cout << 3 << "\n";
        cout << 3 << " ";
        ll m = n - 3;

        for (ll p = 2; p <= m; ++p)
        {
            if (is_prime(p) && is_prime(m - p))
            {
                cout << p << " " << (m - p) << "\n";
                break;
            }
        }
    }

    return 0;
}
