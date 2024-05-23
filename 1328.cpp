#include <stdio.h>
#define MOD 1000000007

using namespace std;

long long int dp[102][102][102];

int main() 
{
    int N,L,R;
    scanf("%d %d %d",&N,&L,&R);
    
    dp[1][1][1] = 1;
    for (int i=2; i<=N; i++) {
        for (int j=1; j<=i; j++) {
            for (int k=1; k<=i; k++) {
                dp[i][j][k] = (dp[i-1][j][k-1] + dp[i-1][j-1][k] + dp[i-1][j][k]*(i-2))%MOD;
            }
        }
    }
    
    printf("%lld",dp[N][L][R]);
}