#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);

    int a[8];
    for (int i=1; i<=6; i++) scanf("%d",&a[i]);

    int t,p;
    scanf("%d %d",&t,&p);

    int ans = 0;
    for (int i=1; i<=6; i++) ans += (a[i]+t-1)/t;
    printf("%d\n%d %d",ans,n/p,n%p);
}