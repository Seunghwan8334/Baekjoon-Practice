#include <iostream>

using namespace std;

int main() 
{
    int n,k;
    cin >> n >> k;
    int ans = 0;
    for (int num=1; num<=n; num++) {
        int tmp = num;
        int num_max = 1;
        for (int j=2; j*j <= num; j++) {
            if (tmp%j == 0) {
                num_max = j;
                while(tmp%j == 0) tmp /= j;
            }
        }
        if (tmp > 1) num_max = tmp; 
        if (num_max <= k) ans++;
    }
    cout << ans;
}