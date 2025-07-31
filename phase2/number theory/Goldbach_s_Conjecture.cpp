#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int N = 1e7 + 5;
bitset<N> prime;

vector<ll> sieve()
{
    prime[1] = 1;
    prime[0] = 1;
    ll sq = sqrt(N) + 2;

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
    for (int i = 3; i <= N; i += 2)
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
    int t;
    cin >> t;
    vector<ll> p = sieve();
    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ":";
        ll n;
        cin >> n;
        ll cnt = 0;
        for (auto it : p)
        {
            if (it <= n)
            {
                ll req = n - it;
                if (req == 2)
                {
                    if (prime[req] == 0 && req <= it)
                    {
                        cnt++;
                    }
                }
                else
                {
                    if ((req % 2 == 1 && prime[req] == 0) && req <= it)
                    {
                        cnt++;
                    }
                }
            }
            else
            {
                break;
            }
        }
        cout << " " << cnt << "\n";
    }
    return 0;
}