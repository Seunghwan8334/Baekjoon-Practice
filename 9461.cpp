#include <iostream>

long long int ans[105];

int main()
{
    ans[1] = 1;
    ans[2] = 1;
    ans[3] = 1;
    ans[4] = 2;
    ans[5] = 2;
    for (int i=6; i<=100; i++) ans[i] = ans[i-5]+ans[i-1];
    
    int t,n;
    std::cin>>t;
    while(t--) {
        std::cin>>n;
        std::cout<<ans[n]<<"\n";
    }
}