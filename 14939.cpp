#include <iostream>
#include <cmath>

using namespace std;

int ans = -1;
char tmp[10][10];
int arr[12][12];
int copied[12][12];

void copyarr() {
    for (int i=1; i<=10; i++) {
        for (int j=1; j<=10; j++) copied[i][j] = arr[i][j];
    }
}

void toggle(int y, int x, int n) {
    if (n == 1) {
        arr[y+1][x] ^= 1;
        arr[y-1][x] ^= 1;
        arr[y][x] ^= 1;
        arr[y][x+1] ^= 1;
        arr[y][x-1] ^= 1;
    } 
    else {
        copied[y+1][x] ^= 1;
        copied[y-1][x] ^= 1;
        copied[y][x] ^= 1;
        copied[y][x+1] ^= 1;
        copied[y][x-1] ^= 1;
    }
}

void loop(int x, int cnt) {
    if (x == 11) {
        copyarr();
        int copycnt = 0;
        for (int i=2; i<=10; i++) {
            for (int j=1; j<=10; j++) {
                if (copied[i-1][j]) {
                    toggle(i,j,2);
                    copycnt++;
                }
            }
        }
        for (int i=1; i<=10; i++) {
            if (copied[10][i]) return;
        }
        if (ans == -1) ans = copycnt+cnt;
        else ans = min(ans,copycnt+cnt);
        return;
    } 
    toggle(1,x,1);
    loop(x+1,cnt+1);
    toggle(1,x,1);
    loop(x+1,cnt);
} 

int main() 
{
    for (int i=0; i<10; i++) cin >> tmp[i];
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (tmp[i][j] == 'O') arr[i+1][j+1] = 1;
        }
    }

    loop(1,0);

    cout << ans;
}