#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
ll modular_exp(ll a, ll b, ll modulus)
{
    // a=base
    // b=exponent
    //  O(log(b))
    ll result = 1;
    a = a % modulus;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (__int128)(result * a) % modulus;
        }
        a = (a * a) % modulus;
        b = b / 2;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b, c;
    cin >> a >> b >> c;
    ll op1 = modular_exp(a, b, c);
    ll op2 = ((a % c) * (b % c)) % c;
    ll op3 = ((a % c) * modular_exp(b, c - 2, c)) % c;
    cout
        << op1 << "\n"
        << op2 << "\n"
        << op3 << "\n";

    return 0;
}