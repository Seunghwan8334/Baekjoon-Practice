#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int arr[300002];
int sum[300002];
int ans[300002];
map <int, int> cnt;
vector <int> v;

int main() 
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr,arr+n);
    for (int i=0; i<n; i++) {
        if (v.empty()) {
            v.push_back(arr[i]);
            cnt.insert({arr[i],1});
        }
        else {
            if (v.back() == arr[i]) cnt[arr[i]]++;
            else {
                v.push_back(arr[i]);
                cnt.insert({arr[i],1});
            }
        }
    }

    sum[0] = cnt[v[0]];
    for (int i=1; i<v.size(); i++) sum[i] = cnt[v[i]]+sum[i-1];

    ans[1] = (v[1]-v[0])*(cnt[0]*cnt[1]);
    for (int i=2; i<v.size(); i++) {
        ans[i] = ans[i-1]*(cnt[i]+1)+sum[i-1]*cnt[i]; // 여기 주변 다 잘못 됨
    }
    printf("%d",ans[v.size()-1]);
}   