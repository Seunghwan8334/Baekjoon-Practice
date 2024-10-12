#include <stdio.h>
#include <math.h>

int a[20];

int main() 
{
    int n;
    scanf("%d",&n);
    
    int lcnt = 0;
    while (pow(2,lcnt) <= n) lcnt++;
    lcnt--;

    for (int i = lcnt; i>=0; i--) {
        if (pow(2,i) <= n) {
            a[i] = 1;
            n -= pow(2,i);
        } 
    }

    for (int i=0; i<=lcnt; i++) {
        if (a[i]) printf("%d ",i);
    }
}