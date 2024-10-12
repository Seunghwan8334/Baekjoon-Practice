#include <stdio.h>
#define MOD 10007

int n;
long long int dp[53][53];
long long int setdp(int n, int r) {
    if (dp[n][r]) return dp[n][r];
    dp[n-1][r-1] = setdp(n-1,r-1);
    dp[n-1][r] = setdp(n-1,r);
    return (dp[n-1][r-1] + dp[n-1][r]);
}

long long int ans(int x, int cnt) {
    if (x > n) return 0;
    if (cnt == 13) {
        if (x == n) return 1;
        else return 0;
    }
    
    long long int sum = 0;
    for (int i=3; i>=0; i--) {
        sum += ans(x+i,cnt+1)*dp[4][i];
    }
    return sum;
}

int main() 
{
    scanf("%d",&n);

    for (int i=1; i<=52; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    for (int i=1; i<52; i++) dp[52][i] = setdp(52,i);

    printf("%lld",(dp[52][n]-ans(0,0))%MOD);
}