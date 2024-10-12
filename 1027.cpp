#include <stdio.h>

using namespace std;

int main() 
{
    int n;
    scanf("%d",&n);

    int ans=0;
    double a[52];
    for (int i=1; i<=n; i++) scanf("%lf",&a[i]);
    for (int i=1; i<=n; i++) {
        int cnt = 0;
        for (int j=1; j<=i-1; j++) {
            int pass = 1;
            double cst = (a[i]-a[j])/(i-j);
            for (int k=j+1; k<=i-1; k++) {
                if (cst*(k-j)+a[j] <= a[k]) pass = 0;
            }
            if (pass) cnt++;
        }
        for (int j=i+1; j<=n; j++) {
            int pass = 1;
            double cst = (a[j]-a[i])/(j-i);
            for (int k=i+1; k<=j-1; k++) {
                if (cst*(k-i)+a[i] <= a[k]) pass = 0;
            }
            if (pass) cnt++;
        }
        if (cnt > ans) ans = cnt;
    }
    printf("%d",ans);
}