#include <stdio.h>
#include <math.h>
#define MAX 2000000000

int lcnt = 0;
int a[140000];
int tree[18][140000];

int ans(int begin, int end, int l, int r, int llcnt, int ll) {
    if (begin <= l && r <= end) return tree[llcnt][ll];
    else if (r < begin || end < l) return 0;
    else {
        int tmp1 = ans(begin, end, l, (l+r)/2, llcnt+1, ll*2);
        int tmp2 = ans(begin, end, (l+r)/2+1, r, llcnt+1, ll*2+1);
        return a[tmp1] <= a[tmp2] ? tmp1 : tmp2; 
    }
    
}

void prttree() {
    for (int i=0; i<=lcnt; i++) {
        for (int j=0; j<pow(2,i); j++) printf("%d ",tree[i][j]);
        printf("\n");
    }
}

int main() 
{
    int n;
    scanf("%d",&n);
    while(pow(2,lcnt) <= n) lcnt++;

    a[0] = MAX;
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);
    for (int i=n+1; i<pow(2,lcnt); i++) a[i] = MAX;
    
    for (int i=0; i<pow(2,lcnt); i++) tree[lcnt][i] = i;
    
    for (int i=lcnt-1; i>=0; i--) {
        for (int j=0; j<pow(2,i); j++) {
            tree[i][j] = a[tree[i+1][j*2]] <= a[tree[i+1][j*2+1]] ? tree[i+1][j*2] : tree[i+1][j*2+1];
        }
    }
    
    int m;
    scanf("%d",&m);
    while(m--) {
        int t,b,c;
        scanf("%d %d %d",&t,&b,&c);
        if (t == 1) {
            a[b] = c;
            b /= 2;
            for (int i=lcnt-1; i>=0; i--) {
                tree[i][b] = a[tree[i+1][b*2]] <= a[tree[i+1][b*2+1]] ? tree[i+1][b*2]:tree[i+1][b*2+1];
                b /= 2;
            }
        }
        else printf("%d\n",ans(b,c,0,pow(2,lcnt)-1,0,0));
    }
}