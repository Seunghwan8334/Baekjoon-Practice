#include <iostream>
#include <vector>

using namespace std;

struct s {
    int x1,y1,x2,y2;
};

int chk[52];
vector <s> v;
vector <int> ans;

int main() 
{
    int n,k;
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v.push_back({x1,y1,x2,y2});
    }

    while (k--) {
        int tmp = 0;
        for (int i=0; i<)
    }

    for (int i=0; i<ans.size(); i++) cout << ans[i]+1 <<" ";
}