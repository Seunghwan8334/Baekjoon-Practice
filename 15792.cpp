#include <stdio.h>
int main() 
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",a/b);
    a %= b;

    if (a) {
        printf(".");
        int cnt = 0;
        while(a) {
            if (cnt++ > 1000) break;
            a *= 10;
            printf("%d",a/b);
            a %= b;
        }
    }
}