#include <iostream>

using namespace std;

int main() 
{
    int n;
    cin >> n;

    int num = 1;
    int ans = 1;
    while(n > num) num += 6*ans++;
    
    cout << ans;
}