#include <stdio.h>
#include <algorithm>

using namespace std;

int a[100003];

int main() 
{
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);

    sort(a+1,a+n+1);
    a[n+1] = 10000000; 
    int tmp = 0;
    int ans = 2000000000;
    for (int i=0; i<=a[n]; i++) {
        while(a[tmp+1] <= i) tmp++;

        if (i+n-tmp < ans) ans = i+n-tmp;
    }

    printf("%d",ans);
}