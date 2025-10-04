#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h;
    cin >> n >> h;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    auto isOk = [&](int mid)
    {
        int height = h;
        vector<int> ck;
        for (int i = 1; i <= mid; i++)
        {
            ck.push_back(v[i]);
        }

        sort(ck.begin(), ck.end(), greater<int>());
        bool f = true;
        if (mid % 2 == 0)
        {
            int cnt = 0;
            int mx = -1;
            for (int i = 0; i < ck.size(); i++)
            {
                mx = max(mx, ck[i]);
                cnt++;
                if (cnt == 2)
                {
                    if (height >= mx)
                    {
                        height -= mx;
                    }
                    else
                    {
                        f = false;
                        break;
                    }
                    mx = -1;
                    cnt = 0;
                }
            }
        }
        else
        {
            int cnt1 = 0;
            int mx1 = -1;
            for (int i = 0; i < ck.size() - 1; i++)
            {
                mx1 = max(mx1, ck[i]);
                cnt1++;
                if (cnt1 == 2)
                {
                    if (height >= mx1)
                    {
                        height -= mx1;
                    }
                    else
                    {
                        f = false;
                        break;
                    }
                    mx1 = -1;
                    cnt1 = 0;
                }
            }
            int last = ck.size() - 1;
            if (height < ck[last])
            {
                f = false;
            }
        }

        return f ? 0 : 1;
    };

    int l = 1, r = n, ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (isOk(mid) == 0)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    cout << ans << "\n";
    return 0;
}
