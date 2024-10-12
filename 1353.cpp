#include <iostream>
#include <vector>

using namespace std;

struct pnums {
    int num;
    int cnt;
};

vector <pnums> pnum;
vector <int> v[1002];
vector <int> nums;

int main() 
{
    int s,p;
    cin >> s >> p;

    for (int i=2; i*i<=p; i++) {
        if (p%i == 0) {
            pnum.push_back({i,1});
            p /= i;
            while(p%i == 0) {
                pnum.back().cnt++;
                p /= i;
            }
        }
    }   
    if (p > 1) pnum.push_back({p,1});

    int MAX = 1;
    for (int i=0; i<pnum.size(); i++) MAX *= (pnum[i].cnt+1);

    int ans = 1;
    while (ans <= MAX) {
        nums.clear();
        for (int i=0; i<ans; i++) nums.push_back(1);
        for (int i=0; i<pnum.size(); i++) {
            
        }

        int sum = 0;
        for (int i=0; i<nums.size(); i++) sum += nums[i];
        if (sum == s) break;

        ans++;
    } 
    if (ans > MAX) cout << "-1";
    else cout << ans;
}