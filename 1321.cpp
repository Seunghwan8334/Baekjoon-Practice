#include <stdio.h>

int tree[21][600000];

int main() 
{
    int n;
    scanf("%d",&n);
    
    int td=0,tl=1;
    while(tl<=n) {
        tl *= 2;
        td++;
    }
    
    for (int i=0; i<n; i++) scanf("%d",&tree[td][i]);
    for (int i=td-1; i>=0; i--) {
        for (int j=0; j<tl; j++) tree[i][j] = tree[i+1][j*2]+tree[i+1][j*2+1];
    }

    int m;
    scanf("%d",&m);
    while(m--) {
        int a,b,c;
        scanf("%d",&a);
        if (a==1) {
            scanf("%d %d",&b,&c);
            tree[td][b-1] += c;
            int tmpl = (b-1)/2;
            for (int i=td-1; i>=0; i--) {
                tree[i][tmpl] = tree[i+1][tmpl*2]+tree[i+1][tmpl*2+1];
                tmpl /= 2;
            }
        }
        else {
            int sum = 0;
            scanf("%d",&b);
            int ll=0;
            for (int i=0; i<td; i++) {
                if (sum+tree[i+1][ll*2] >= b) ll *= 2;
                else {
                    sum += tree[i+1][ll*2];
                    ll = ll*2+1;
                }
            }
            printf("%d\n",ll+1);
        }
    }
}