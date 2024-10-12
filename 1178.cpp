#include <iostream>
#include <vector>

using namespace std;

vector <int> v[1002];
vector <int> tmp;

int chk[1002][1002];

int main() 
{
    int n,m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        chk[a][b] = 1;
        chk[b][a] = 1;
    }


}