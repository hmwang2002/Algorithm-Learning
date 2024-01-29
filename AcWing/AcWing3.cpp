#include <iostream>

using namespace std;

const int N = 1005;
int v[N], w[N];
int f[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = v[i]; j <= m; j++) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    printf("%d", f[m]);
    return 0;
}

/**
 * 01背包：f[i][j] = max(f[i - 1][j], f[i - 1][j - v] + w);
 * 完全背包：f[i][j] = max(f[i - 1][j], f[i][j - v] + w);
 */