#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

struct s {
    int num;
    int cnt;
};

struct cmp {
    bool operator()(s p1, s p2) {
        return p1.cnt > p2.cnt;
    }
};

int n;
int ans[1002][1002];
int chk[1002];
priority_queue<s, vector<s>, cmp> pq;
vector <s> v[802];

void set_ans(int x) {
    for (int i=0; i<=n; i++) ans[x][i] = -1;
    for (int i=0; i<=n; i++) chk[i] = 0;
    pq.push({x,0});
    while(!pq.empty()) {
        int num = pq.top().num;
        int cnt = pq.top().cnt;
        pq.pop();

        if (chk[num]) continue;
        ans[x][num] = cnt;
        chk[num] = 1;

        for (int i=0; i<v[num].size(); i++) {
            int vnum = v[num][i].num;
            int vcnt = v[num][i].cnt;
            pq.push({vnum,cnt+vcnt});
        }   
    }
} 

int main() 
{
    int e;
    scanf("%d %d",&n,&e);
    for (int i=1; i<=e; i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);

        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    int v1,v2;
    scanf("%d %d",&v1,&v2);

    set_ans(1);
    set_ans(v1);
    set_ans(v2);
    set_ans(n);

    if ((ans[1][v1] == -1 || ans[v1][v2] == -1 || ans[v2][n] == -1) && (ans[1][v2] == -1 || ans[v2][v1] == -1 || ans[v1][n] == -1)) printf("-1");
    else if (ans[1][v1] == -1 || ans[v1][v2] == -1 || ans[v2][n] == -1) printf("%d",ans[1][v2]+ans[v2][v1]+ans[v1][n]);
    else if (ans[1][v2] == -1 || ans[v2][v1] == -1 || ans[v1][n] == -1) printf("%d",ans[1][v1]+ans[v1][v2]+ans[v2][n]);
    else printf("%d",min(ans[1][v1]+ans[v1][v2]+ans[v2][n],ans[1][v2]+ans[v2][v1]+ans[v1][n]));
}