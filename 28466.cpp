#include <stdio.h>

using namespace std;

int x[1000002];
int s[1000002][2];
int a[12][12];
int b[14][14];

int main() 
{
    int n;
    scanf("%d",&n);

    for (int i=1; i<=10; i++) {
        for (int j=1; j<=10; j++) scanf("%d",&a[i][j]);
    }

    for (int i=1; i<=12; i++) {
        for (int j=1; j<=12; j++) scanf("%d",&b[i][j]);
    }

    for (int i=1; i<=n; i++) scanf("%d %s",&x[i],s[i]);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j) continue;
            printf("x[%d] = %d, x[%d] = %d, a[%d][%d] = %d, b[%d][%d] = %d\n",i,x[i],j,x[j],i,j,a[i][j],i,j,b[i][j]);
        }
    }
}