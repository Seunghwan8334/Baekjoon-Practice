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
vector <s> v[1002];

int chk[1002];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1; i<=m; i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    
    int ans = 0;
    pq.push({1,0});
    while(!pq.empty()) {
        int num = pq.top().num;
        int cnt = pq.top().cnt;
        pq.pop();

        if (chk[num]) continue;
        chk[num] = 1;
        ans += cnt;

        for (int i=0; i<v[num].size(); i++) {
            int vnum = v[num][i].num;
            int vcnt = v[num][i].cnt;

            if (chk[vnum]) continue;
            pq.push({vnum,vcnt});
        }
    }
    printf("%d",ans);
}