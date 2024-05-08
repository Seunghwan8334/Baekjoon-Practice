#include <iostream>
#include <queue>

using namespace std;

queue <pair<int,int>> q;

char a[103][103];
int chk1[103][103];
int chk2[103][103];
int yy[4] = {0,-1,0,1};
int xx[4] = {-1,0,1,0};

int main() 
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];

    int ans1 = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (!chk1[i][j]) {
                chk1[i][j] = ans1;
                q.push({i,j});
                while(!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int k=0; k<4; k++) {
                        int ny = y+yy[k];
                        int nx = x+xx[k];
                        if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1) continue;
                        
                        if (a[ny][nx] == a[y][x] && !chk1[ny][nx]) {
                            chk1[ny][nx] = ans1;
                            q.push({ny,nx});
                        }
                    }
                }
                ans1++;
            }
        }
    }

    int ans2 = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (!chk2[i][j]) {
                chk2[i][j] = ans2;
                q.push({i,j});
                while(!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int k=0; k<4; k++) {
                        int ny = y+yy[k];
                        int nx = x+xx[k];
                        if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1) continue;
                        if (!chk2[ny][nx]) {
                            if (a[y][x] == 'B') {
                                if (a[ny][nx] == 'B') {
                                    chk2[ny][nx] = ans2;
                                    q.push({ny,nx});
                                }
                            }
                            else {
                                if (a[ny][nx] == 'B') continue;
                                chk2[ny][nx] = ans2;
                                q.push({ny,nx});
                            }
                        }
                    }
                }
                ans2++;
            }
        }
    }

    printf("%d %d",ans1-1,ans2-1);
}