#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long int arr1[17];
long long int arr2[17];

struct s {
    long long int num;
    long long int cnt;
};

vector <s> v1;
vector <s> v2;

vector <s> ans1;
vector <s> ans2;

bool cmp (const s& p1, const s& p2) {
    return p1.num < p2.num;
};

struct ubc {
    bool operator()(const s& p1, const s& p2) {
        return p1.num < p2.num;
    }
};

int main() 
{
    int n,c;
    cin >> n >> c;

    int idx1=0;
    for (int i=1; i<=n/2; i++) cin >> arr1[idx1++];
    int idx2=0;
    for (int i=n/2+1; i<=n; i++) cin >> arr2[idx2++];

    v1.push_back({0,1});
    for (int i=0; i<idx1; i++) {
        int tmp = arr1[i];
        vector <s> tmpv;
        for (int j=0; j<v1.size(); j++) {
            long long int num = v1[j].num;
            long long int cnt = v1[j].cnt;
            tmpv.push_back({num+tmp,cnt});
            tmpv.push_back({num,cnt});
        }
        v1.clear();
        for (int j=0; j<tmpv.size(); j++) {
            long long int num = tmpv[j].num;
            long long int cnt = tmpv[j].cnt;
            v1.push_back({num,cnt});
        }
    }

    v2.push_back({0,1});
    for (int i=0; i<idx2; i++) {
        int tmp = arr2[i];
        vector <s> tmpv;
        for (int j=0; j<v2.size(); j++) {
            long long int num = v2[j].num;
            long long int cnt = v2[j].cnt;
            tmpv.push_back({num+tmp,cnt});
            tmpv.push_back({num,cnt});
        }
        v2.clear();
        for (int j=0; j<tmpv.size(); j++) {
            long long int num = tmpv[j].num;
            long long int cnt = tmpv[j].cnt;
            v2.push_back({num,cnt});
        }
    }
    sort(v1.begin(),v1.end(),cmp);
    sort(v2.begin(),v2.end(),cmp);

    for (int i=0; i<v1.size(); i++) {
        long long int num = v1[i].num;
        long long int cnt = v1[i].cnt;
        if (ans1.empty()) ans1.push_back({num,cnt});
        else if (ans1.back().num == num) ans1.back().cnt += cnt;
        else ans1.push_back({num,cnt});
    }
    for (int i=0; i<v2.size(); i++) {
        long long int num = v2[i].num;
        long long int cnt = v2[i].cnt;
        if (ans2.empty()) ans2.push_back({num,cnt});
        else if (ans2.back().num == num) ans2.back().cnt += cnt;
        else ans2.push_back({num,cnt});
    }

    for (int i=1; i<ans2.size(); i++) ans2[i].cnt += ans2[i-1].cnt;

    long long int ans = 0;
    for (int i=0; i<ans1.size(); i++) {
        long long int num = ans1[i].num;
        long long int cnt = ans1[i].cnt;
        if (ans2[0].num+num > c) continue;

        int idx = upper_bound(ans2.begin(),ans2.end(),s{c-num,0},ubc())-ans2.begin();
        ans += cnt*ans2[idx-1].cnt;
    }
    cout << ans;
}