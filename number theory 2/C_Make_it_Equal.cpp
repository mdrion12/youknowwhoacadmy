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
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        map<int, ll> mp;
        vector<ll> v(n), t(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            v[i] %= k;
            mp[v[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> t[i];
            t[i] %= k;
        }
        sort(t.begin(), t.end());
        // for (auto it : mp)
        // {
        //     cout << it.first << " " << it.second << "\n";
        // }
        bool f = true;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp.count(t[i]) > 0)
            {
                mp[t[i]]--;
                count++;
                if (mp[t[i]] == 0)
                {

                    mp.erase(t[i]);
                }
            }
            else
            {
                // cout << "ekhane2\n";
                ll op1 = t[i] + k;
                ll op2 = abs(t[i] - k);
                // cout << op1 << " " << op2 << "\n";
                if (mp.count(op1) > 0 && mp[op1] > 0)
                {
                    count++;
                    mp[op1]--;
                    if (mp[op1] == 0)
                    {
                        mp.erase(op1);
                    }
                }
                else if (mp.count(op2) > 0 && mp[op2] > 0)
                {
                    count++;
                    mp[op2]--;
                    if (mp[op2] == 0)
                    {
                        mp.erase(op2);
                    }
                }
                else
                {
                    f = false;
                    break;
                }
            }
        }
        if (f == false || mp.size() > 0)
        {
            no
        }
        else
        {
            yes
        }
        // for (int i = 0; i < n; i++)

        // {
        //     cout << v[i] << " ";
        // }
        // cout << "\n";
        // for (int i = 0; i < n; i++)
        // {
        //     cout << t[i] << " ";
        // }
        // cout << "\n";
    }

    return 0;
}