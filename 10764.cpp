#include <iostream>

using namespace std;

int n,m;
char a[52][52];
int by[8] = {1,1,1,0,0,-1,-1,-1};
int bx[8] = {1,0,-1,1,-1,1,0,-1};

int f(int y, int x) {
    if (0 <= y && y < n && 0 <= x && x < m) return 1;
    return 0;
}

int main() 
{
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i];

    int ans = 0;
    for (char i='A'; i<='Z'; i++) {
        for (char j='A'; j<='Z'; j++) {
            if (i == j) continue;
            if (i == 'M' || j == 'O') continue;
            int mx = 0;
            for (int y=0; y<n; y++) {
                for (int x=0; x<m; x++) {
                    char now = a[y][x];
                    if (now == i) {
                        for (int k=0; k<8; k++) {
                            int yy1 = y+by[k];
                            int xx1 = x+bx[k];
                            int yy2 = y+by[k]*2;
                            int xx2 = x+bx[k]*2;
                            if (f(yy1,xx1) && f(yy2,xx2) && a[yy1][xx1] == j && a[yy2][xx2] == j) mx++;
                        }
                    }
                }
            }
            if (mx > ans) ans = mx;
        }
    } 
    cout << ans;
}