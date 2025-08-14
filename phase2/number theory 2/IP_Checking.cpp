
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "No" << "\n";
#define yes cout << "Yes" << "\n";
ll modular_exp(ll a, ll b)
{
    // a=base
    // b=exponent
    //  O(log(b))
    ll result = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * a);
        }
        a = (a * a);
        b = b / 2;
    }
    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        string s, ss;
        cin >> s >> ss;
        string a = "", b = "", c = "", d = "";
        string w = "", x = "", y = "", z = "";
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '.')
            {
                cnt++;
            }
            else if (cnt == 0)
            {
                a += s[i];
            }
            else if (cnt == 1)
            {
                b += s[i];
            }
            else if (cnt == 2)
            {
                c += s[i];
            }
            else if (cnt == 3)
            {
                d += s[i];
            }
        }
        cnt = 0;
        for (int i = 0; i < ss.size(); i++)
        {
            if (ss[i] == '.')
            {
                cnt++;
            }
            else if (cnt == 0)
            {
                w += ss[i];
            }
            else if (cnt == 1)
            {
                x += ss[i];
            }
            else if (cnt == 2)
            {
                y += ss[i];
            }
            else if (cnt == 3)
            {
                z += ss[i];
            }
        }
        // cout << a << " " << b << " " << c << " " << d << " \n";
        // cout << w << " " << x << " " << y << " " << z << " \n";
        reverse(w.begin(), w.end());
        ll op1 = 0, op2 = 0, op3 = 0, op4 = 0;
        for (int i = 0; i < w.size(); i++)
        {
            if (w[i] == '1')
            {
                op1 += modular_exp(2, i);
            }
        }
        reverse(x.begin(), x.end());
        for (int i = 0; i < x.size(); i++)
        {
            if (x[i] == '1')
            {
                op2 += modular_exp(2, i);
            }
        }
        reverse(y.begin(), y.end());
        for (int i = 0; i < x.size(); i++)
        {
            if (y[i] == '1')
            {
                op3 += modular_exp(2, i);
            }
        }
        reverse(z.begin(), z.end());
        for (int i = 0; i < x.size(); i++)
        {
            if (z[i] == '1')
            {
                op4 += modular_exp(2, i);
            }
        }
        string p1, p2, p3, p4;
        p1 = to_string(op1);
        p2 = to_string(op2);
        p3 = to_string(op3);
        p4 = to_string(op4);
        cout << "Case " << k << ": ";
        if (p1 == a and p2 == b and p3 == c and p4 == d)
        {
            yes
        }
        else
        {
            no
        }
    }
    return 0;
}