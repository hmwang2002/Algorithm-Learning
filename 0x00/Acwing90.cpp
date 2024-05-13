#include <bits/stdc++.h>

using namespace std;

auto _{
    []() noexcept
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr), std::cout.tie(nullptr);
        return 0;
    }()};

typedef long long ll;

ll mul(ll a, ll b, ll p)
{
    long long ans = 0;
    for (; b; b >>= 1)
    {
        if (b & 1)
            ans = (ans + a) % p;
        a = a * 2 % p;
    }
    return ans;
}

int main()
{
    ll a, b, p;
    cin >> a >> b >> p;
    cout << mul(a, b, p) << endl;
}