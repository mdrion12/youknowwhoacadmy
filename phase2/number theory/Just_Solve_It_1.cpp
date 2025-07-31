
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const ll N = 3e5 + 9;
vector<ll> lpx(N + 1);
vector<ll> gpx(N + 1);
vector<ll> prime(N + 1, 0);

void initialize()
{
    for (ll i = 1; i <= N; i++)
    {
        lpx[i] = i;
        gpx[i] = 0;
    }
}
void sieve()
{
    ll sq = sqrt(N) + 2;
    for (ll i = 2; i <= sq; i += 1)
    {
        if (prime[i] != 1)
        {
            for (ll j = 2 * i; j <= N; j += i)
            {
                prime[j] = 1;
                lpx[j] = min(lpx[j], i);
                gpx[j] = max(gpx[j], i);
            }
        }
    }
    for (ll i = 2; i <= N; i++)
    {
        if (prime[i] == 0)
        {
            lpx[i] = gpx[i] = i;
        }
    }
}
map<ll, ll> getFactorization(ll x)
{
    map<ll, ll> mp;
    vector<ll> res;
    while (x != 1)
    {
        res.push_back(lpx[x]);
        mp[lpx[x]]++;
        x /= lpx[x];
    }
    return mp;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    initialize();
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        ll v;
        cin >> v;
        map<ll, ll> mp = getFactorization(v);
        ll totalnumberordivisor = 1;
        ll sumofdivisor = 1;
        ll tpf = 0;
        for (auto it : mp)
        {
            totalnumberordivisor *= (it.second + 1);
            tpf += it.second;
            sumofdivisor *= round(pow(it.first, it.second + 1) - 1) / (it.first - 1);
        }
        cout << lpx[v] << " " << gpx[v] << " " << mp.size() << " " << tpf << " " << totalnumberordivisor << " " << sumofdivisor << "\n";
    }
    return 0;
}