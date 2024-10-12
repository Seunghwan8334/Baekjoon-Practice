#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair <int,int> p[10002];

bool cmp(pair <int,int> p1, pair <int,int> p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
}

vector <pair<int,int>> v;

int main() 
{
    int N,L;
    cin >> N >> L;
    for (int i=0; i<N; i++) {
        int a,b;
        cin >> a >> b;
        p[i] = {a,b};
    }

    sort(p,p+N,cmp);

    int cc = 0;
    int ss = 0;
    int ee = 0;

    for (int i=0; i<N; i++) {
        int a = p[i].first;
        int b = p[i].second-1;

        if (cc == 0) {
            ss = a;
            ee = b;
            cc = 1;
        }
        else {
            if (ee < a) {
                v.push_back({ss,ee});
                ss = a;
                ee = b;
            } 
            else if (ee < b) ee = b;
        }
    }
    v.push_back({ss,ee});

    int ans = 0;
    int LL = 0;
    for (int i=0; i<v.size(); i++) {
        int a = v[i].first;
        int b = v[i].second;

        if (LL < a) {
            int dis = b-a+1;
            int cnt = (dis-1)/L+1;
            LL = a+cnt*L-1;
            ans += cnt;
        }
        else if (a <= LL && LL < b) {
            a = LL+1;
            int dis = b-a+1;
            int cnt = (dis-1)/L+1;
            LL = a+cnt*L-1;
            ans += cnt;
        }
        else if (b <= LL) continue;
    }
    cout << ans;
}