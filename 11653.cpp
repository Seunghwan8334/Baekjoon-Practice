#include <iostream>

int main() 
{
    int n = (std::cin>>n, n);
    for (int i=2; i*i<=n; i++) {
        while(n%i==0) (std::cout << i << "\n", n /= i);
    }
    if (n > 1) std::cout << n;
}