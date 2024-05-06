#include <iostream>
#include <cmath>

using namespace std;

char a[753][753];
int LTR[753][753];
int RTL[753][753];

int main() 
{
    int n,m,ans=0;
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i];

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == '1') LTR[i][j]++;
            if (a[i][j] == '1') RTL[i][j]++;
            if (0<i && 0<j) LTR[i][j] += LTR[i-1][j-1];
            if (0<i && j<m-1) RTL[i][j] += RTL[i-1][j+1];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int num = min(min(i,n-1-i),min(j,m-1-j));

            if (a[i][j] == '1' && ans < 1) ans=1;
            for (int k=1; k<=num; k++) {
                int cnt = 0;
                if (a[i-k][j] == '1') cnt++;
                cnt += RTL[i][j-k] - RTL[i-k][j];
                cnt += LTR[i][j+k] - LTR[i-k][j];
                cnt += RTL[i+k][j] - RTL[i][j+k];
                cnt += LTR[i+k][j] - LTR[i][j-k];
                if (a[i+k][j] == '1') cnt--;
    
                if (cnt == k*4 && ans < k+1) ans=k+1;
            }
        }
    }
    printf("%d",ans);
}