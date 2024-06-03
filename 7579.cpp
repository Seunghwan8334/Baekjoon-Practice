#include <stdio.h>
#include <math.h>

using namespace std;

long long int save[102][10001];
int memo[101];
int cost[101];
        
int main() 
{   
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; i++) scanf("%d", &memo[i]);
    for (int i=1; i<=n; i++) scanf("%d", &cost[i]);

    for (int i=1; i<=n; i++) {
        save[i+1][cost[i]] = save[i][0]+memo[i];
        for (int j=0; j<=10000; j++) {
            if (save[i][j]) {
                save[i+1][j+cost[i]] = max(save[i][j]+memo[i],save[i+1][j+cost[i]]);
                save[i+1][j] = max(save[i][j],save[i+1][j]);
            }   
        }
    }

    for (int i=0; i<=10000; i++) {
        if (save[n+1][i] >= m) {
            printf("%d",i); 
            break;
        }
    }
}