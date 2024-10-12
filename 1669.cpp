#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int x,y;
    cin >> x >> y;

    int dif = y-x;
    int ans = 0;
    int cnt = 1;
    while(1) {
        if (dif >= cnt) {
            dif -= cnt;
            ans++;    
        }
        else break;
        if (dif >= cnt) {
            dif -= cnt;
            ans++;    
        }
        else break;
        cnt++;
    }
    if (dif) ans++;
    cout << ans;
}