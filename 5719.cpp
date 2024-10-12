#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct s {
    int num;
    int cnt;
};

struct cmp {
    bool operator()(s p1, s p2) {
        return p1.cnt > p2.cnt;
    }
};

priority_queue <s, vector<s>, cmp> pq;
vector <pair<int,int>> v[502];

int N,M,S,D;
int chk[502];
int chk2[502][502];
int shortest = -1;

int dfs(int num, int cnt) {

    if (cnt > shortest) return 0;

    if (num == D) {
        chk[num] = 0;
        if (cnt == shortest) return 1;
        else return 0;
    }

    int T = 0;
    for (int i=0; i<v[num].size(); i++) {
        int next = v[num][i].first;
        int ncnt = v[num][i].second;
        if (chk2[num][next]) continue;
        if (chk[next]) continue;
        chk[next] = 1;
        if (dfs(next,cnt+ncnt) == 1) {
            chk2[num][next] = 1;
            T = 1;
        }
        chk[next] = 0;
    }
    return T;
}

void dijkstra() {
    pq.push({S,0});
    while(!pq.empty()) {
        int num = pq.top().num;
        int cnt = pq.top().cnt;
        pq.pop();

        if (num == D) {
            shortest = cnt;
            break;
        }

        if (chk[num]) continue;
        chk[num] = 1;

        for (int i=0; i<v[num].size(); i++) {
            int next = v[num][i].first;
            int ncnt = v[num][i].second;
            pq.push({next,cnt+ncnt});
        }
    }

    while(!pq.empty()) pq.pop();
    for (int i=0; i<N; i++) chk[i] = 0;
}

int main() 
{
    while(1) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        cin >> S >> D;

        while(M--) {
            int U,V,P;
            cin >> U >> V >> P;
            v[U].push_back({V,P});
        }

        shortest = -1;

        dijkstra();

        if (shortest == -1) {
            cout << "-1\n";
            continue;
        }

        chk[S] = 1;
        dfs(S,0);
        chk[S] = 0;

        int ans=-1;

        pq.push({S,0});
        while(!pq.empty()) {
            int num = pq.top().num;
            int cnt = pq.top().cnt;
            pq.pop();

            if (num == D) {
                ans = cnt;
                break;
            }

            if (chk[num]) continue;
            chk[num] = 1;

            for (int i=0; i<v[num].size(); i++) {
                int next = v[num][i].first;
                int ncnt = v[num][i].second;
                if (chk2[num][next]) continue;
                pq.push({next,cnt+ncnt});
            }
        }
        while(!pq.empty()) pq.pop();

        cout << ans << "\n";

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) chk2[i][j] = 0;
        }
        for (int i=0; i<N; i++) chk[i] = 0;
        for (int i=0; i<N; i++) v[i].clear();
    }
}