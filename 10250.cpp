#include <stdio.h>
int main() 
{
    int t;
    scanf("%d",&t);
    while(t--) {
        int h,w,n;
        scanf("%d %d %d",&h,&w,&n);
        int cnt=1;
        for (int i=1; i<=w; i++) {
            for (int j=1; j<=h; j++) {
                if (cnt == n) {
                    printf("%d",j);
                    if (i < 10) printf("0%d",i);
                    else printf("%d",i);
                    printf("\n");
                }
                cnt++;
            }
        }
    }
}