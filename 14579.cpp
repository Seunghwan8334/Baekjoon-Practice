#include <stdio.h>
int main() 
{
    int a,b,ans=1;
    scanf("%d %d",&a,&b);
    for (int i=a; i<=b; i++) {
        int sum = ((1+i)*i)/2;
        sum %= 14579;
        ans *= sum;
        ans %= 14579;
    }
    printf("%d",ans);
}