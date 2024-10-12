#include <stdio.h>
#include <vector>

using namespace std;

struct s {
    int num;
    int cnt;
};

vector <s> v[40002];

int tree[40002];
int mom[40002];
int dis[40002];

void set_rank(int x, int cnt) {
    for (int i=0; i<v[x].size(); i++) {
        int vnum = v[x][i].num;
        int vcnt = v[x][i].cnt;
        if (tree[vnum]) continue;

        mom[vnum] = x;
        dis[vnum] = vcnt;
        tree[vnum] = cnt+1;
        set_rank(vnum,cnt+1);
    }
}

int main() 
{
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n-1; i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    tree[1] = 1;
    set_rank(1,1);

    int m;
    scanf("%d",&m);
    for (int i=1; i<=m; i++) {
        int a,b,ans=0;
        scanf("%d %d",&a,&b);
        while(tree[a] < tree[b]) {
            ans += dis[b];
            b = mom[b];
        }
        while(tree[a] > tree[b]) {
            ans += dis[a];
            a = mom[a];
        }

        while(a != b) {
            ans += dis[a];
            ans += dis[b];
            a = mom[a];
            b = mom[b];
        }
        printf("%d\n",ans);
    }
}