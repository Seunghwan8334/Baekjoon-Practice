#include <stdio.h>

int m[20][20];

int f(int r, int c, int y, int x) {
    int cnt = 0; 
    while (1) {
        int p=0;
        if (y+cnt+1 >= r || x+cnt+1 >= c) break;
        for (int i=y; i <= y+cnt+1; i++) {
            for (int j=x; j <= x+cnt+1; j++) {
                if (m[i][j] == 1) p++;
            }
        }
        if (p > 0) break;
        cnt++;
    }
    return cnt; 
}

int main() 
{
    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        int r, c, k;
        scanf("%d %d %d", &r, &c, &k);
        for (int j = 1; j <= k; j++) {
            int a, b;
            scanf("%d %d", &a, &b);
            m[a][b] = 1; // Adjusting for zero-based index
        }
        
        int ans = 0;
        
        for (int y = 0; y < r; y++) {
            for (int x = 0; x < c; x++) {
                if (m[y][x] == 0) ans += f(r, c, y, x)+1; 
            }
        }

        for (int y = 0; y < r; y++) {
            for (int x = 0; x < c; x++) m[y][x] = 0;
        }

        printf("Case #%d: %d\n", i, ans); 
    }
    return 0;
}
