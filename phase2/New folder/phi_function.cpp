#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db long double
#define vii vector<ll>
#define pll pair<ll, ll>
#define F first
#define S second

const ll N = (ll)1e6 + 5;
const ll mod = (ll)1e9 + 7;
const ll inf = (ll)1e18;

int phi[N];
void phi_1_to_n(int n)
{
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

ll phi_n(ll n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {

            while (n % i == 0)
            {
                n /= i;
            }

            result -= result / i;
        }
    }
    if (n > 1)
    {
        result -= result / n;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    phi_1_to_n(1000000);
    int t = 1;
    cin >> t;
    while (true)
    {
    }
}