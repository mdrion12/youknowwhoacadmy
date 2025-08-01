#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int N = 2e7 + 5;
bitset<N> prime;
vector<ll> sieve()
{
    int sq = sqrt(N) + 2;

    for (ll i = 3; i <= sq; i += 2)
    {
        if (prime[i] == 1)
        {
            continue;
        }
        for (ll j = i * i; j <= N; j += 2 * i)
        {
            if (prime[j] != 1)
            {
                prime[j] = 1;
            }
        }
    }
    vector<ll> ans;
    ans.push_back(2);
    for (ll i = 3; i <= N; i += 2)
    {
        if (prime[i] == 0)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<ll> p = sieve();
    vector<pair<ll, ll>> tp;
    for (int i = 0; i < p.size(); i++)
    {
        if ((p[i + 1] - p[i]) == 2)
        {
            tp.push_back({p[i], p[i + 1]});
        }
    }
    int t;
    while (cin >> t)
    {

        pair<ll, ll> pr = tp[t - 1];
        cout << "(" << pr.first << ", " << pr.second << ")" << "\n";
    }
    return 0;
}