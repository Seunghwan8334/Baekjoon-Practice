#include <stdio.h>

int a[2003];
int p[2003][2003];

int main() 
{
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);

    for (int i=1; i<=n; i++) p[i][i] = 1;
    for (int i=1; i<=n-1; i++) {
        if (a[i] == a[i+1]) p[i][i+1] = 1;
    }

    for (int i=2; i<n; i++) {
        for (int j=1; j<=n-i; j++) {
            if (p[j+1][j+i-1] && (a[j] == a[j+i])) p[j][j+i] = 1; 
        }
    }

    int m;
    scanf("%d",&m);
    while(m--) {
        int s,e;
        scanf("%d %d",&s,&e);
        printf("%d\n",p[s][e]);
    }
}