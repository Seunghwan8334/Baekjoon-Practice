#include <iostream>
#include <cmath>
#include <map>

#define MAX 2000000000

using namespace std;

pair <int,int> nx[1005];

int ans[1005][1005];

int dis(int a, int b) {
    return abs(nx[a].first-nx[b].first)+abs(nx[a].second-nx[b].second);
}

int main() 
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    int cp1 = 1001;
    int cp2 = 1002;    
    nx[cp1] = {1,1};
    nx[cp2] = {n,n};

    for (int i=1; i<=m; i++) {
        int a,b;
        cin >> a >> b;
        nx[i] = {a,b};
    }

    for (int i=1; i<=m; i++) {
        for (int j=1; j<=m; j++) ans[i][j] = MAX;
    }

    ans[cp1][1] = dis(1,cp2);
    ans[1][cp2] = dis(cp1,1);

    for (int i=2; i<=m; i++) {
        ans[cp1][i] = ans[cp1][i-1]+dis(i,i-1);
        ans[i][cp2] = ans[i-1][cp2]+dis(i,i-1);
        ans[i][i-1] = ans[cp1][i-1]+dis(cp1,i);
        ans[i-1][i] = ans[i-1][cp2]+dis(i,cp2);
        for (int j=1; j<=i-2; j++) {
            if (ans[i][i-1] > ans[j][i-1]+dis(j,i)) ans[i][i-1] = ans[j][i-1]+dis(i,j); 
            if (ans[i-1][i] > ans[i-1][j]+dis(i,j)) ans[i-1][i] = ans[i-1][j]+dis(i,j); 
            if (ans[i][j] > ans[i-1][j]+dis(i-1,i)) ans[i][j] = ans[i-1][j]+dis(i,i-1);
            if (ans[j][i] > ans[j][i-1]+dis(i,i-1)) ans[j][i] = ans[j][i-1]+dis(i,i-1);
        }
    }

    int ANS = MAX;
    if (ANS > ans[cp1][m]) ANS = ans[cp1][m];
    if (ANS > ans[m][cp2]) ANS = ans[m][cp2];

    for (int i=1; i<=m-1; i++) {
        if (ANS > ans[m][i]) ANS = ans[m][i];
        if (ANS > ans[i][m]) ANS = ans[i][m];
    }
    

    cout << ANS << "\n";  
}