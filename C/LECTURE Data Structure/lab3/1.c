#include <stdio.h>
#define MAXN 10005
#define MAXW 10000005

int n, W, w[MAXN], v[MAXN];
long long f[MAXW]; 

int main() {
    scanf("%d %d", &W, &n); 
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &w[i], &v[i]);
    for (int i = 1; i <= n; i++)
        for (int l = w[i]; l <= W; l++)
            if (f[l - w[i]] + v[i] > f[l])
                f[l] = f[l - w[i]] + v[i];
    printf("%lld", f[W]);
    return 0;
}