#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int f[N];
int v[N], w[N];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    for(int i = 1; i <= n; i++) {
        // 一定得逆序：https://www.acwing.com/solution/content/116859/
        for(int j = m; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}







// 最暴力的方法，二维数组。
// int n,m;
// int f[N][N];
// int v[N], w[N];

// int main() {
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];

//     for(int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++)
//         {
//             f[i][j] = f[i - 1][j];
//             if (j >= v[i]) {
//                 f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
//             }
//         }
//     }
//     int res = 0;
//     for(int i = 0; i <= m; i++) res = max(res, f[n][i]);
//     cout << res << endl;

//     return 0;
// }

