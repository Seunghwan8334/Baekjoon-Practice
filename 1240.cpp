#include <stdio.h>
#include <vector>

using namespace std;

struct s {
    int num;
    int cnt;
};

int chk[1002];
vector <s> v[1002];

void f(int a, int b, int cnt) {
    if (a == b) {
        printf("%d\n",cnt);
        return;
    }
    for (int i=0; i<v[a].size(); i++) {
        int num = v[a][i].num;
        if (chk[num]) continue;
        chk[num] = 1;
        f(num,b,cnt+v[a][i].cnt);
    }
}

int main() 
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n-1; i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    for (int i=1; i<=m; i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        chk[a] = 1;
        f(a,b,0);
        for (int j=1; j<=n; j++) chk[j] = 0;
    }
}