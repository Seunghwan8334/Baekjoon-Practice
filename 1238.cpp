#include <stdio.h>
#include <vector>
#include <queue>

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

priority_queue <s,vector<s>,cmp> pq;
vector <s> cv[1002];
vector <s> rv[1002];

int ans[1002][1002];

int main() 
{
    int n,m,x;
    scanf("%d %d %d",&n,&m,&x);
    for (int i=1; i<=m; i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        cv[a].push_back({b,c});
        rv[b].push_back({a,c});
    }

    pq.push({x,0});
    while(!pq.empty()) {
        int num = pq.top().num;
        int cnt = pq.top().cnt;
        pq.pop();

        for (int i=0; i<rv[num].size(); i++) {
            int vnum = rv[num][i].num;
            int vcnt = rv[num][i].cnt;

            if (ans[vnum][x] && ans[vnum][x] < cnt+vcnt) continue;

            ans[vnum][x] = cnt+vcnt;
            pq.push({vnum,cnt+vcnt});
        }
    }

    pq.push({x,0});
    while(!pq.empty()) {
        int num = pq.top().num;
        int cnt = pq.top().cnt;
        pq.pop();

        for (int i=0; i<cv[num].size(); i++) {
            int vnum = cv[num][i].num;
            int vcnt = cv[num][i].cnt;

            if (ans[x][vnum] && ans[x][vnum] < cnt+vcnt) continue;

            ans[x][vnum] = cnt+vcnt;
            pq.push({vnum,cnt+vcnt});
        }
    }
    ans[x][x] = 0;

    int max = 0;
    for (int i=1; i<=n; i++) {
        if (ans[i][x]+ans[x][i] > max) max = ans[i][x]+ans[x][i];
    }
    printf("%d",max);
}