#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r) {
    if(l >= r) return;
    // 这边i,j写成两侧，而不是直接取l,r，如果下面新区间用j，那么这边不能取x = q[r]，因为可能会出现j = r的情况，这样就会出现死循环; 如果下面新区间用i，那么这边不能取x = q[l]，因为可能会出现i = l的情况，这样就会出现死循环
    int x = q[l], i = l - 1, j = r + 1;
    while(i < j) {
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);

    for(int i = 0; i < n; i++) printf("%d ", q[i]);

    return 0;
}