#include <iostream>
#include <vector>

using namespace std;

vector <int> v;
vector <int> sv;

int n,ans=200000000;
int arr[22][22];

int f() {
    for (int i=1; i<=n; i++) {
        int found = 0;
        for (int j=0; j<v.size(); j++) {
            if (v[j] == i) found = 1;
        }
        if (found) continue;
        sv.push_back(i);
    }

    int total1= 0;
    for (int i=0; i<v.size(); i++) {
        for (int j=0; j<v.size(); j++) total1 += arr[v[i]][v[j]];
    }
    int total2 = 0;
    for (int i=0; i<sv.size(); i++) {
        for (int j=0; j<sv.size(); j++) total2 += arr[sv[i]][sv[j]];
    }
    sv.clear();
    return total1>total2?total1-total2:total2-total1;
}

void loop(int x, int cnt) {
    if (cnt == n/2) {
        int tmp = f();
        if (tmp < ans) ans = tmp;
        return;
    }
    for (int i=x+1; i<=n; i++) {
        v.push_back(i);
        loop(i,cnt+1);   
        v.pop_back();
    }
}

int main() 
{
    cin >> n;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) cin >> arr[i][j];
    }

    
    v.push_back(1);
    loop(1,1);
    v.pop_back();
    
    cout << ans;
}