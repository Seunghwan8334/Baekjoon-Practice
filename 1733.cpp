#include <stdio.h>

int possible = 1;
pair <int,int> p[1000002];
int ans[1000002];
int visited[1000002];
int 

int match(int x) {
    if (visited[x]) return 0;

    visited[x] = 1;

    if ()

}

int main() 
{
    int n;
    scanf("%d",&n);

    for (int i=1; i<=n; i++) scanf("%d %d",&p[i].first,&p[i].second);

    for (int i=1; i<=n; i++) {
        if (!match(i)) {
            possible = 0;
            break;
        }
    }
    
    if (possible) {
        for (int i=1; i<=n; i++) printf("%d\n",ans[i]);
    }
    else printf("-1");
}