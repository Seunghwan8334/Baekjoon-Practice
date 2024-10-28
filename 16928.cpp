#include <iostream>
#include <queue>

using namespace std;

int ladder[110];
int snake[110];
int dp[110];

struct cmp {
    bool operator()(pair<int,int>p1, pair<int,int>p2) {
        return p1.second > p2.second;
    }
};

priority_queue <pair<int,int>, vector<pair<int,int>>, cmp> q;

int main() 
{
    int n,m;
    cin >> n >> m;

    while(n--) {
        int a,b;
        cin >> a >> b;
        ladder[a] = b;
    }    
    while(m--) {
        int a,b;
        cin >> a >> b;
        snake[a] = b;
    }

    q.push({1,0});
    while(!q.empty()) {
        int num = q.top().first;
        int cnt = q.top().second;
        q.pop();

        if (cnt > 0 && num == 1) continue; 

        if (dp[num]) continue;
        dp[num] = cnt;

        for (int i=1; i<=6; i++) {
            int next = num+i;
            if (next > 100) continue;
            if (ladder[next]) q.push({ladder[next],cnt+1});
            else if (snake[next]) q.push({snake[next],cnt+1});
            else q.push({next,cnt+1});
        }
    }
    cout << dp[100];
}