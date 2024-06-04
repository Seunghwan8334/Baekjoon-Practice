#include <stdio.h>
#include <vector>

using namespace std;

vector <int> v[202];

int visited[202];
int matched[202];

int match(int x) {
    for (int i=0; i<v[x].size(); i++) {
        int num = v[x][i];
        if (visited[num]) continue;
        visited[num] = 1;
        if (!matched[num] || match(matched[num])) {
            matched[num] = x;   
            return 1;
        }
    }
    return 0;
}

int main() 
{
    int n,m,ans=0;
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; i++) {
        int tmp;
        scanf("%d",&tmp);
        while(tmp--) {
            int num;
            scanf("%d",&num);
            v[i].push_back(num);
        }
    }

    for (int i=1; i<=n; i++) {
        if (match(i)) ans++;
        for (int j=1; j<=m; j++) visited[j] = 0;
    }
    printf("%d",ans);
}