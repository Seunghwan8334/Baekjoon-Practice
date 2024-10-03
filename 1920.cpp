#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
    int n;
    scanf("%d",&n);

    int arr[100002];
    for (int i=0; i<n; i++) scanf("%d",&arr[i]);
    
    sort(arr,arr+n); 
    
    int m;
    scanf("%d",&m);

    for (int i=0; i<m; i++) {
        int num;
        scanf("%d",&num);

        int l = 0;
        int r = n-1;
        while(l < r) {
            int mid = (l+r)/2;
            if (arr[mid] < num) l = mid+1;
            else if (num <= arr[mid]) r = mid;
        }
        if (arr[r] == num) printf("1\n");
        else printf("0\n");
    }
}