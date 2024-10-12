#include <stdio.h>
#include <algorithm>

using namespace std;

int a[52];

bool cmp(int p1, int p2) {
    return p1+1 != p2;
}

int main() 
{
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%d",&a[i]);

    sort(a,a+n);
    sort(a,a+n,cmp);

    for (int i=0; i<n; i++) printf("%d ",a[i]);
}