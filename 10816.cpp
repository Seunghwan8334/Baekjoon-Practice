#include <iostream>
#include <algorithm>

int n,arr[500002];

int main() 
{
    scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%d",&arr[i]);

    std::sort(arr,arr+n);

    int m,num;
    scanf("%d",&m);
    while(m--) {
        scanf("%d",&num);
        int L = std::lower_bound(arr,arr+n,num)-arr;
        int R = std::upper_bound(arr,arr+n,num)-arr;
        printf("%d ",R-L);
    }
}
