#include <stdio.h>
#include <math.h>
#define ll long long int 

using namespace std;

ll a[3002];
ll s[3002][3002];
ll sum[3002];

int main() 
{
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) scanf("%lld",&a[i]);
    for (int i=1; i<=n; i++) sum[i] = sum[i-1]+a[i];
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n-k+1; i++) s[i][k] = sum[i+k-1]-sum[i-1];
    }
    
    int ansk = 0;
    ll ans = 40000000000000;
    for (int k=1; 2*k<=n; k++) {
        for (int i=1; i-1+2*k<=n; i++) {
            for (int j=i+k; j+k-1<=n; j++) {
                if (abs(s[j][k]-s[i][k]) <= ans) {
                    ans = abs(s[j][k]-s[i][k]);
                    ansk = k;
                }

            }
        }
    }
    printf("%d\n%lld",ansk,ans);
}