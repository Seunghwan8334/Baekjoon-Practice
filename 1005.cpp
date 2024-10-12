#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

int D[1002];
int time[1002];
int chk[1002];

vector <int> v[1002];

void f(int x) {
    int tmp = 0;
    for (int i=0; i<v[x].size(); i++) {
        int num = v[x][i];
        if (!chk[num]) f(num);
        chk[num] = 1;
        
        if (time[num] > tmp) tmp = time[num];
    }
    time[x] = tmp+D[x];
}

int main() 
{
    int t;
    scanf("%d",&t);
    while(t--) {
        int n,k,w;
        scanf("%d %d",&n,&k);
        for (int i=1; i<=n; i++) scanf("%d",&D[i]);
        for (int i=1; i<=k; i++) {
            int a,b;
            scanf("%d %d",&a,&b);
            v[b].push_back(a);
        }
        scanf("%d",&w);
        f(w);
        printf("%d\n",time[w]);
        for (int i=1; i<=n; i++) time[i] = 0;
        for (int i=1; i<=n; i++) chk[i] = 0;
        for (int i=1; i<=n; i++) v[i].clear();
    }
}