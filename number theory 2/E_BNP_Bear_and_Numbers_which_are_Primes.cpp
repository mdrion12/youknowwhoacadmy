#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;

vector<int> freq(N, 0);
vector<long long> f(N, 0);
vector<long long> prefix(N, 0);
vector<bool> isPrime(N, true);

void sieve()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * 2; j < N; j += i)
            {
                isPrime[j] = false;
            }
            for (int j = i; j < N; j += i)
            {
                f[i] += freq[j];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        if (v < N)
            freq[v]++;
    }

    sieve();

    for (int i = 1; i < N; i++)
    {
        prefix[i] = prefix[i - 1] + f[i];
    }

    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        if (l >= N)
        {
            cout << 0 << "\n";
            continue;
        }
        r = min(r, N - 1);
        cout << prefix[r] - prefix[l - 1] << "\n";
    }

    return 0;
}
