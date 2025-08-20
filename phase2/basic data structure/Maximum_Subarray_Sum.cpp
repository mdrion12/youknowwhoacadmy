#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    long long ans = LLONG_MIN;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        ans = max(ans, (long long)v[i]);
        if (sum < 0)
        {
            sum = 0;
            continue;
        }
        ans = max(ans, sum);
    }
    cout << ans << "\n";
}