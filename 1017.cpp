#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v[53];
vector <int> ans;

int arr[53];
int matched[53];
int visited[53];

int prime(int x) {
    if (x == 1) return 0;
    for (int i=2; i*i <=x; i++) {
        if (x%i == 0) return 0;
    }
    return 1;
}

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
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) scanf("%d",&arr[i]);
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (prime(arr[i]+arr[j])) {
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    for (int i=0; i<v[1].size(); i++) {
        int num = v[1][i];
        int chk = 1;
        for (int j=1; j<=n; j++) matched[j] = 0;
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=n; k++) visited[k] = 0;
            visited[1] = 1;
            visited[num] = 1;
            if (visited[j]) continue;
            if (!match(j)) {
                chk = 0;
                break;
            }
        }
        if (chk) ans.push_back(arr[num]);
    }

    sort(ans.begin(), ans.end());
    if (ans.empty()) printf("-1");
    else {
        for (int i=0; i<ans.size(); i++) printf("%d ",ans[i]);
    }
}