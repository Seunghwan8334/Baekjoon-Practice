#include <iostream>
#include <algorithm>

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n,m;
    int arr[100003];
    std::cin >> n >> m;
    for (int i=0; i<n; i++) std::cin>>arr[i];
    int max = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] > max) max = arr[i];
    }

    int l=max,r=1000000000,ans=1000000000;
    while(l<=r) {
        int mid = (l+r)/2;

        int cnt = 1;
        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += arr[i];
            if (sum > mid) {
                sum = arr[i];
                cnt++;
            }
        }
        
        if (cnt > m) l = mid+1;
        else {
            ans = ans>mid?mid:ans;
            r = mid-1;
        }
    }
    std::cout<<ans;
}