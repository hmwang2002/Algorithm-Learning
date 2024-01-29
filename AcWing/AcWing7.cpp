#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int f[N];
int v[N], w[N];
int n, m;

int main() {
    cin >> n >> m;
    int t = 0;
    while(n--) {
        int a, b, s;
        cin >> a >> b >> s;
        if(s == -1) {
            s = 1;
        } else if(s == 0) {
            s = m / a;
        }
        for (int i = 1; i <= s; i *= 2) {
            v[++t] = i * a;
            w[t] = i * b;
            s -= i;
        }
        if(s > 0) {
            v[++t] = s * a;
            w[t] = s * b;
        }
    }

    for (int i = 1; i <= t; i++) {
        for (int j = m; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    cout << f[m] << endl;
    return 0;
}