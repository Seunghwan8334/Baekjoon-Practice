#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
    int n,c,ans=0;
    std::cin >> n >> c;
    std::vector<int>v(n);  
    for (int i=0; i<n; i++) std::cin >> v[i];
    sort(v.begin(),v.end());

    int L=1, R=1000000000;
    while (L<=R) {
        int distance = (L+R)/2;
        int count=1, idx=0;

        while(lower_bound(v.begin(),v.end(),v[idx]+distance) != v.end()) {
            idx = lower_bound(v.begin(),v.end(),v[idx]+distance)-v.begin(); 
            count+=1;
        }
        
        if (count < c) R = distance-1;
        else L = distance+1;
    }
    std::cout << R;
}