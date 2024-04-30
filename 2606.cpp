#include <stdio.h>
int main() 
{
    int n,m;
    scanf("%d %d",&n,&m);
    int ans = 0;
    for (int i=1; i<=n; i++) ans += m;
    printf("%d",ans-1);
}