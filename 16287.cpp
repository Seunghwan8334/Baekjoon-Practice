#include <iostream>

using namespace std;

int a[5003];
pair <int,int> sv1[800003];
pair <int,int> sv2[800003];

int main() 
{
    int w,n;
    cin >> w >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (sv1[a[i]+a[j]].first == 0) sv1[a[i]+a[j]] = {i,j};
            else if (sv1[a[i]+a[j]].second > j) sv1[a[i]+a[j]] = {i,j};
            
            if (sv2[a[i]+a[j]].first == 0) sv2[a[i]+a[j]] = {i,j};
            else if (sv2[a[i]+a[j]].first < i) sv2[a[i]+a[j]] = {i,j};
        }
    }
    int ans = 0;
    for (int i=2; i<=w-2; i++) {
        if (sv1[i].first > 0 && sv2[w-i].first > 0 && sv1[i].second < sv2[w-i].first) ans = 1;
    }
    if (ans) cout << "YES";
    else cout << "NO";
}