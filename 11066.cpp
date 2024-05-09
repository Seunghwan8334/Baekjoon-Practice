#include <stdio.h>
#include <math.h>

using namespace std;

int sum[503];
int dp[503][503];

int main() 
{
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        for (int i=1; i<=n; i++) {
            scanf("%d",&sum[i]);
            sum[i] += sum[i-1];
        }
        
        for (int i=1; i<=n-1; i++) { // 차이
            for (int j=1; j+i<=n; j++) { // j번째 수부터 j+i번째 수까지의 최소비용
                dp[j][j+i] = dp[j][j]+dp[j+1][j+i]+sum[j+i]-sum[j-1];
                for (int k=j+1; k<=j+i; k++) dp[j][j+i] = min(dp[j][j+i],dp[j][k]+dp[k+1][j+i]+sum[j+i]-sum[j-1]);
            }
        }
        printf("%d\n",dp[1][n]);
    }
}