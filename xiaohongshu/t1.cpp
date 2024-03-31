#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    double res = 2.0 / ((double)n * (double)(n - 1));
    printf("%.10f", res);
}