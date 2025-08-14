#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int N = 1e5 + 5;
int par[N];
int group_size[N];
int level[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
        level[i] = 0;
    }
}
int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union_by_level(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if (level[leaderA] > level[leaderB])
    {
        par[leaderB] = leaderA;
    }
    else if (level[leaderB] > level[leaderA])
    {
        par[leaderA] = leaderB;
    }
    else
    {
        par[leaderA] = leaderB;
        level[leaderB]++;
    }
}
void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if (group_size[leaderA] > group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}
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
            result = (result * a) % modulus;
        }
        a = (a * a) % modulus;
        b = b / 2;
    }
    return result;
}
vector<int> sieve()
{
    const int N = 3e5 + 9;
    int sq = sqrt(N) + 2;
    vector<int> prime(N, 0);
    for (int i = 3; i <= sq; i += 2)
    {
        if (prime[i] == 1)
        {
            continue;
        }
        for (int j = i * i; j <= N; j += 2 * i)
        {
            if (prime[j] != 1)
            {
                prime[j] = 1;
            }
        }
    }
    vector<int> ans;
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
vector<int> divisors(int n)
{
    vector<int> divisor;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisor.push_back(i);
            if (i != n / i)
            {
                divisor.push_back(n / i);
            }
        }
    }
    return divisor;
}
bool is_prime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    int v = (a * b) / gcd(a, b);
    return v;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v1(n), v2(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> v1[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> v2[i];
        }
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (v1[i] > v2[i])
            {
                sum += (v1[i] - v2[i]);
            }
        }
        cout << (sum + 1) << "\n";
    }
    return 0;
}