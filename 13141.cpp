#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct s {
    int num;
    int len;
};

struct cmp {
    bool operator()(s p1, s p2) {
        return p1.len > p2.len;
    }
};

priority_queue <s, vector<s>, cmp> pq;

vector <s> v[202];

int main() 
{
    int n,m,chk[202],ans=2000000000;
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    for (int t=1; t<=n; t++) {
        int tmp = 0;
        pq.push({t,0});
        while(!pq.empty()) {
            int num = pq.top().num;
            int dis = pq.top().dis;
            pq.pop();

            if (dis > tmp) tmp = dis;

            for (int i=0; i<v[num].size(); i++) {
                int next = v[num][i].num;
                int len = v[num][i].len;
                if (chk[next] == 1) continue;
                pq.push({next,dis+len});
            }
        }
        if (tmp < ans) ans = tmp;
    }
    cout << ans;
}