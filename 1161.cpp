#include <stdio.h>
#include <algorithm>

using namespace std;

struct s {
    int Si;
    int Ei;
    int Mi;
};

bool cmp (s p1, s p2) {
    return p1.Si < p2.Si;
};

s a[50002];

int main() 
{
    int k,n,c;
    scanf("%d %d %d",&k,&n,&c);

    for (int i=1; i<=k; i++) scanf("%d %d %d",&a[i].Si,&a[i].Ei,&a[i].Mi);

    sort(a+1,a+k+1,cmp);
    
    for (int i=1; i<=k; i++) printf("%d %d %d\n",a[i].Si,a[i].Ei,a[i].Mi);
}