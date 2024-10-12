#include <stdio.h>
#include <queue>

using namespace std;

struct s {
    int y;
    int x;
    int cnt;
};

queue <s> q;

int chk[302][302];
int ay[] = {1,2,2,1,-1,-2,-2,-1};
int ax[] = {-2,-1,1,2,-2,-1,1,2};

int main() 
{
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);

        int sy,sx;
        scanf("%d %d",&sy,&sx);
        int ey,ex;
        scanf("%d %d",&ey,&ex);
        q.push({sy,sx,0});
        while(!q.empty()) {
            int y = q.front().y;
            int x = q.front().x;
            int cnt = q.front().cnt;
            q.pop();

            if (y == ey && x == ex) {
                printf("%d\n",cnt);
                break;
            }

            for (int i=0; i<8; i++) {
                int yy = y+ay[i];
                int xx = x+ax[i];
                if (0 <= yy && yy < n && 0 <= xx && xx < n) {
                    if (chk[yy][xx]) continue;
                    chk[yy][xx] = 1;
                    q.push({yy,xx,cnt+1});
                }
            }
        }
        while(!q.empty()) q.pop();
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) chk[i][j] = 0;
        }
    }
}