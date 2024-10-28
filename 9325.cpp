#include <stdio.h>

int main() 
{
    int t;
    scanf("%d",&t);
    while(t--) {
        int s;
        scanf("%d",&s);
        int n;
        scanf("%d",&n);
        while(n--) {
            int q,p;
            scanf("%d %d",&q,&p);
            s += p*q;
        }
        printf("%d\n",s);
    }
}