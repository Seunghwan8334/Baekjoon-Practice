#include <stdio.h>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector <int> v[104];
queue <int> q;
pair<int,int> p[104];
int chk[104];

int main() 
{
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        for (int i=1; i<=n+2; i++) scanf("%d %d",&p[i].first,&p[i].second);
        for (int i=1; i<=n+2; i++) {
            for (int j=i+1; j<=n+2; j++) {
                if (abs(p[i].first-p[j].first)+abs(p[i].second-p[j].second) <= 1000) {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        int ans = 0;
        q.push(1);
        chk[1] = 1;
        while(!q.empty()) {
            int num = q.front();
            q.pop();

            if (num == n+2) ans = 1;
            for (int i=0; i<v[num].size(); i++) {
                if (chk[v[num][i]]) continue;
                chk[v[num][i]] = 1;
                q.push(v[num][i]);
            }
        }

        if (ans) printf("happy\n");
        else printf("sad\n");

        while(!q.empty()) q.pop();
        for (int i=1; i<=102; i++) chk[i] = 0;
        for (int i=1; i<=102; i++) v[i].clear();
    }
}
