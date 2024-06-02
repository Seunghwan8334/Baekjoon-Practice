#include <iostream>
#include <vector>

using namespace std;

vector <int> v[26];

int n,k,ans=0,mx=-1;
int ncnt[50];

void loop(int x, int cnt) {
    if (cnt == k) {
        if (ans > mx) mx = ans;
        return;
    }
    for (int i=x; i<26-k+1+cnt; i++) {
        for (int j=0; j<v[i].size(); j++) {
            if (ncnt[v[i][j]] == 1) ans++;
            ncnt[v[i][j]]--;
        }
        loop(i+1,cnt+1);
        for (int j=0; j<v[i].size(); j++) {
            if (ncnt[v[i][j]] == 0) ans--;
            ncnt[v[i][j]]++;
        }
    }
}

int main() 
{
    scanf("%d %d",&n,&k);

    for (int i=0; i<n; i++) {
        string tmp;
        cin >> tmp;
        for (int j=0; j<tmp.length(); j++) {
            int num = tmp[j]-'a';
            if (v[num].empty()) {
                v[num].push_back(i);
                ncnt[i]++;
            }
            else if (v[num].back() != i) {
                v[num].push_back(i);
                ncnt[i]++;
            }
        }
    }
    loop(0,0);
    cout << mx;
}
