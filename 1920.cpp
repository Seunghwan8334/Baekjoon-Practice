#include <iostream>
#include <algorithm>

int main() 
{
    int n;
    scanf("%d",&n);

    int arr[100002];
    for (int i=0; i<n; i++) scanf("%d",&arr[i]);
    
    std::sort(arr,arr+n); 
    
    int m,num;
    scanf("%d",&m);
    
    for (int i=0; i<m; i++) {
        scanf("%d",&num);

        int l=0,r=n-1;
        while(l < r) {
            int mid = (l+r)/2;
            if (arr[mid] < num) l = mid+1;
            else if (num <= arr[mid]) r = mid;
        }
        if (arr[r] == num) printf("1\n");
        else printf("0\n");
    }
}
