#include <iostream>

int arr[102][102];

int main() 
{
    int t;
    std::cin>>t;

    while(t--) {
        int x,y;
        std::cin>>x>>y;
        for (int i=y; i<y+10; i++) {
            for (int j=x; j<x+10; j++) {
                arr[i][j] = 1;
            }
        }
    }
    int ans = 0;
    for (int i=1; i<=100; i++) {
        for (int j=1; j<=100; j++) {
            if (arr[i][j] == 1) ans++;
        }
    }
    std::cout<<ans;
}