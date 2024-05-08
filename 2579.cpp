#include <stdio.h>
#include <math.h>

using namespace std;

int a[303];
int dp[3][303];

int main() 
{
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);

    for (int i=1; i<=n; i++) {
        dp[0][i] = max(dp[1][i-1],dp[2][i-1]);
        dp[1][i] = dp[0][i-1]+a[i];
        if (i>=2) dp[2][i] = dp[1][i-1]+a[i];
    }
    printf("%d",max(dp[1][n],dp[2][n]));
}
