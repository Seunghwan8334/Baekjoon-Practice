#include <stdio.h>
#include <math.h>

using namespace std;

int ans = 2000000001;
int a[100002];

int main() 
{
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    int l = 0;
    int r = n-1;
    int ansl = 0;
    int ansr = n-1;
    while (l < r) {
        if (abs(a[l]+a[r]) < ans) {
            ans = abs(a[l]+a[r]);
            ansl = l;
            ansr = r;
        }
        if (abs(a[l+1]+a[r]) < abs(a[l]+a[r-1])) l++;
        else r--;
    }
    printf("%d %d",a[ansl],a[ansr]);
}