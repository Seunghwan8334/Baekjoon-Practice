#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[502][502];

vector <pair<int,int>> v;

bool cmp(pair<int,int> p1, pair<int,int> p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
}

int main() 
{
    int n;
    cin >> n;

    for (int i=1; i<=n; i++) {
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    
    sort(v.begin(),v.end(),cmp);

    for (pair<int,int>p : v) {
        int a = p.first;
        int b = p.second;

        for (int i=1; i<a; i++) {
            for (int j=1; j<b; j++) {
                if (dp[i][j]+1 > dp[a][b] && dp[i][j] > 0) dp[a][b] = dp[i][j] + 1; 
            }
        }
        if (dp[a][b] == 0) dp[a][b] = 1;
    }
    int ans = 0;
    for (int i=1; i<=500; i++) {
        for (int j=1; j<=500; j++) {
            if (dp[i][j] > ans) ans = dp[i][j];
        }
    }
    cout << n-ans;
}