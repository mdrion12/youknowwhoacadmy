#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
vector<int> divisors(int n)
{
    vector<int> divisor;
    for (ll i = 1; i * i <= n; i++)
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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    if (n == m)
    {
        cout << "infinity" << "\n";
        return 0;
    }
    vector<int> d = divisors(abs(n - m));
    int cnt = 0;
    for (int i = 0; i < d.size(); i++)
    {
        if (d[i] > m)
        {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}