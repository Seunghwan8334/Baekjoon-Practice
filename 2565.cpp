#include <stdio.h>
#include <algorithm>

using namespace std;

int a[502];
int b[502];

int main() 
{
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        int A,B;
        scanf("%d %d",&A,&B);
        a[i] = A;
        b[A] = B;
    }

    sort(a,a+n);

    for (int i=0; i<n; i++) {
        printf("%d %d\n",a[i],b[a[i]]);
    }
    
}   