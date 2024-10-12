#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[10005];

int last() {
    for (int i=0; i<n; i++) {
        if (a[i] != n-i) return 0;
    }
    return 1;
}

int main() 
{
    scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    
    if (last()) printf("-1");
    else {
        for (int i=n-2; i>=0; i--) {
            if (a[i] < a[i+1]) {
                int mni = i+1;
                for (int j=i+1; j<n; j++) {
                    if (a[i] < a[j] && a[j] < a[mni]) mni = j;
                }
                int tmp = a[i];
                a[i] = a[mni];
                a[mni] = tmp;
                for (int j=0; j<=i; j++) printf("%d ",a[j]);
                sort(a+i+1,a+n);
                for (int j=i+1; j<n; j++) printf("%d ",a[j]);
                break;
            }
        }
    }
}