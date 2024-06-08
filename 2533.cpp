#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

vector <int> v[1000002];

int dp[2][1000002];
int chk[1000002];

void dfs(int x) {
    dp[1][x] = 1;
    chk[x] = 1;
    for (int i = 0; i < v[x].size(); i++) {
        int num = v[x][i];

        if (chk[num]) continue;

        dfs(num);
        dp[1][x] += min(dp[0][num],dp[1][num]);
        dp[0][x] += dp[1][num];
    }
}

int main() 
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);
    printf("%d",min(dp[1][1],dp[0][1]));
}
