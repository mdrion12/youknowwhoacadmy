#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        cout << "Case " << i << ": " << n << " = ";
        for (int i = 1; i <= n; i++)
        {
            if (is_prime(i))
            {

                int exp = 0;
                for (int j = 1; j <= n; j++)
                {
                    int x = j;
                    while (x % i == 0)
                    {
                        exp++;
                        x /= i;
                    }
                }
                if (i != 2)
                    cout << " * "; // if not the first prime
                cout << i << " (" << exp << ")";
            }
        }
        cout << endl;
    }
    return 0;
}
