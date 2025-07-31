#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e7 + 5;
int spf[N];
void sieveSPF()
{
    for (int i = 2; i < N; ++i)
        spf[i] = i;
    for (int i = 2; i * i < N; ++i)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < N; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}
map<int, int> getFactorization(int x)
{
    map<int, int> mp;
    while (x != 1)
    {

        mp[spf[x]]++;
        x /= spf[x];
    }
    return mp;
}

int main()
{
    sieveSPF();

    ll x;
    while (true)
    {
        cin >> x;
        if (x == 0)
        {
            return 0;
        }
        map<int, int> factors = getFactorization(x);
        cout << x << " : " << factors.size() << "\n";
    }

    return 0;
}
