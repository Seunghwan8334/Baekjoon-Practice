#include <iostream>

using namespace std;

int main() 
{
    int n,l;
    cin >> n >> l;
    int ansFound = 0;
    for (int i=l; i<=100; i++) {
        if (ansFound == 1) break;

        int num = n-(i*(i-1))/2;
        if (num < 0) break;
        if (num%i == 0) {
            ansFound = 1;
            for (int j=0; j<i; j++) cout << num/i+j << " ";
        }
    }
    if (ansFound == 0) cout << -1;
}