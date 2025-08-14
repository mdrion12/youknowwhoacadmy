#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 9;

bool is_prime[N];
vector<int> primes;
void sieve()
{
    is_prime[1] = false;
    for (int i = 2; i < N; i++)
    {
        is_prime[i] = true;
    }
    for (int i = 2; i < N; i++)
    {
        if (is_prime[i])
        {
            for (int j = i + i; j < N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i < N; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();

    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        int ans = 1e9;
        for (int p : primes)
        {
            if (p > m)
                break;
            if (m % p == 0)
            {
                int e = 0;
                while (m % p == 0)
                {
                    m /= p;
                    ++e;
                }
                int exponent_in_n_fact = 0;
                for (int i = 1; i <= n; i++)
                {
                    int x = i;
                    while (x % p == 0)
                    {
                        exponent_in_n_fact++;
                        x /= p;
                    }
                }
                ans = min(ans, exponent_in_n_fact / e);
            }
        }
        cout << "Case " << ++cs << ":\n";
        if (ans == 0)
            cout << "Impossible to divide\n";
        else
            cout << ans << '\n';
    }
    return 0;
}