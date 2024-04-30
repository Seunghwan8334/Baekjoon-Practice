#include <stdio.h>
#include <vector>

using namespace std;

vector <int> v[103];

int chk[103];

int ans(int x) {
    chk[x] = 1;
    int result = 1;
    for (int i=0; i<v[x].size(); i++) {
        int num = v[x][i];
        if (chk[num]) continue;
        result += ans(num);
    }
    return result;
}

int main() 
{
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    for (int i=1; i<=m; i++) {
        int a,b;
       scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    printf("%d",ans(1)-1);
}