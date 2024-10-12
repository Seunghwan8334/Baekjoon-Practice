#include <stdio.h>
#include <math.h>

using namespace std;

int cnt = 0;
long long int a[250002];

int main() 
{
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%lld",&a[i]);

    int ans = 0;
    for (int i=1; i<n; i++) {
        if (a[i-1] > a[i]*pow(2,cnt)) {
            while(a[i-1] > a[i]*pow(2,cnt)) cnt++;
            a[i] *= pow(2,cnt);
            ans += cnt;
        }
        else {
            int l = 0;
            int r = cnt;
            while(l < r) {
                int mid = (l+r)/2;
                if (a[i-1] <= a[i]*pow(2,mid)) r = mid;
                else l = mid+1;
            }
            a[i] *= pow(2,l);
            ans += l;
        }
    }
    printf("%d",ans);
    return 0;
}