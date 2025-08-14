#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    if (a == b)
        cout << a << "\n"; // a এবং b সমান হলে GCD = a
    else
        cout << 1 << "\n"; // ভিন্ন হলে GCD সবসময় 1
    return 0;
}
