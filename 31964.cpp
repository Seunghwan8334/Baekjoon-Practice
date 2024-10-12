#include <stdio.h>

using namespace std;

int a[3002];
int T[100000002];

int main() 
{
    int n;
    scanf("%d",&n);
    int dis=0;
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
        if (a[i] > dis) dis = a[i];
    }
    for (int i=0; i<n; i++) scanf("%d",&T[a[i]]);
    
    int ans = dis;
    for (int i=dis; i>=1; i--) {
        if (T[i] > ans) ans = T[i];
        ans++;
    }

    printf("%d",ans);
}