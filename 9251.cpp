#include <iostream>
#include <math.h>

using namespace std;

int dp[1002][1002];

int main() 
{
    string a;
    string b;
    cin >> a >> b;

    for (int i=0; i<a.length(); i++) {
        for (int j=0; j<b.length(); j++) {
            if (a[i] == b[j]) dp[i][j]++;
            if (i == 0 && j == 0) continue;
            else if (i == 0) dp[i][j] = max(dp[i][j],dp[i][j-1]);
            else if (j == 0) dp[i][j] = max(dp[i][j],dp[i-1][j]);
            else dp[i][j] = max(dp[i-1][j],max(dp[i][j-1],dp[i][j]+dp[i-1][j-1]));
        }
    }
    cout << dp[a.length()-1][b.length()-1];
}