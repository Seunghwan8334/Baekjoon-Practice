#include <stdio.h>
#include <cmath>

using namespace std;

long long int tree[24][1050000];

long long int sum(int begin, int end, int l, int r, int ld, int ll) {
    if (l <= begin && end <= r) return tree[ld][ll];
    if (r < begin || end < l) return 0;
    int mid = (begin+end)/2;
    return sum(begin,mid,l,r,ld+1,ll*2)+sum(mid+1,end,l,r,ld+1,ll*2+1);
}

int main() 
{
    int n,m;
    scanf("%d %d",&n,&m);

    int ld = 0;
    while(pow(2,ld) <= n) ld++;

    while(m--) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);

        if (a) {
            tree[ld][b] = c;
            int tmp = b/2;
            for (int i=ld-1; i>=0; i--) {
                tree[i][tmp] = tree[i+1][tmp*2]+tree[i+1][tmp*2+1];
                tmp /= 2;
            }
        }
        else {
            if (b > c) {
                int d = b;
                b = c;
                c = d;
            }
            printf("%lld\n",sum(0,int(pow(2,ld)-1),b,c,0,0));
        }
    }
}