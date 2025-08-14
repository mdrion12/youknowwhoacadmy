#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int N = 1e8;
bitset<N> prime;
vector<int> sieve()
{
    int sq = sqrt(N) + 2;

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> v = sieve();
    for (int i = 0; i < v.size(); i += 100)
    {
        cout << v[i] << "\n";
    }
    return 0;
}