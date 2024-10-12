#include<stdio.h>
#include<algorithm>

using namespace std;

int a[10000];

int main() {
    int n,k,ans=0;
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);

    sort(a, a+n);

    int tmp = 0;
    for (int i=0; i<n; i++) {
        if (a[i]-a[tmp]>k) tmp++;
        if (ans < i-tmp+1) ans = i-tmp+1;
    }
    printf("%d", ans);
    return 0;
}