#include <stdio.h>
#include <algorithm>
#include <cstdlib>

using namespace std;

int a[52];

int main() 
{
    int n;
    scanf("%d",&n);

    for (int i=0; i<n; i++) scanf("%d",&a[i]);

    sort(a,a+n);

    while(1) {
        
    }
    for (int i=0; i<n; i++) printf("%d ",a[i]);
}