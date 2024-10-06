#include <iostream>
#include <map>

using namespace std;

map <int,int> M;

int main() 
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    while(n--) {
        int tmp;
        cin >> tmp;
        if (M.find(tmp) == M.end()) M.insert({tmp,1});
        else M[tmp]++;
    }

    int m;
    cin >> m;
    while(m--) {
        int tmp;
        cin >> tmp;
        if (M.find(tmp) == M.end()) cout << "0 ";
        else cout << M[tmp] << " ";
    }
}