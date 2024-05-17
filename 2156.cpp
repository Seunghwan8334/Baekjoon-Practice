#include <stdio.h>
#include <math.h>

using namespace std;

int a[10003];
int dp[3][10003];

int main() 
{
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);

    dp[1][1] = a[1];
    for (int i=2; i<=n; i++) {
        dp[0][i] = max(dp[0][i-1],max(dp[1][i-1],dp[2][i-1]));
        dp[1][i] = dp[0][i-1]+a[i];
        dp[2][i] = dp[1][i-1]+a[i];
    }

    printf("%d",max(dp[0][n],max(dp[1][n],dp[2][n])));
}