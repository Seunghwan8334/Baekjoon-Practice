#include <stdio.h>

int arr[2002][2002];
char c_arr[2002][2002];

int sum_v[2002][2002];
int sum_m[2002][2002];

int main() 
{
    int n,m,k;
    scanf("%d %d %d\n",&n,&m,&k);

    for (int i=0; i<n; i++) scanf("%s",c_arr[i]);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (c_arr[i][j] == 'B') arr[i][j] = 1;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) sum_v[i][j] = arr[i][j] ^ (i+j)%2;
    }

    for (int j=m-1; j>=0; j--) {
        for (int i=n-1; i>=0; i--) {
            sum_v[i][j] += sum_v[i+1][j];
            sum_m[i][j] = sum_v[i][j]+sum_m[i][j+1];
        }
    }
    int ans = 200000000;
    for (int i=0; i<n-k+1; i++) {
        for (int j=0; j<m-k+1; j++) {
            int cnt = sum_m[i][j]-sum_m[i+k][j]-sum_m[i][j+k]+sum_m[i+k][j+k];
            if (cnt < ans) ans = cnt;
            if (k*k-cnt < ans) ans = k*k-cnt;
        }
    }
    printf("%d",ans);
}