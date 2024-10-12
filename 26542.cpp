#include <stdio.h>

char a[101][101];

int main() 
{
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        for (int i=0; i<n; i++) {
            scanf("%s",a[i]);
        }

        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (a[i][j] == '.') {
                    int obs = 0;
                    int cnt = 1;
                    while(1) {
                        if (i+cnt-1 >= n || j+cnt-1 >= n) break;
                        for (int ii = i; ii<=i+cnt-1; ii++) {
                            for (int jj = j; jj<=j+cnt-1; jj++) {
                                if (a[ii][jj] == '#') obs++;
                            }
                        }
                        if (obs) break;
                        if (cnt*cnt > ans) ans = cnt*cnt;
                        cnt++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}