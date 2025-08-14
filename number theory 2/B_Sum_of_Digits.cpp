#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    if (s.size() == 1)
    {
        cout << 0 << "\n";
        return 0;
    }
    int count = 0;
    while (1)
    {
        int sum = 0;

        for (auto it : s)
        {
            sum += it - '0';
        }
        count++;
        if (sum < 10)
        {
            break;
        }

        s = to_string(sum);
        // cout << s << "\n";
    }
    cout << count << "\n";
    return 0;
}