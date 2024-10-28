#include <iostream>
#include <set>

using namespace std;

set <int> s;

int main() 
{
    cin.tie(NULL); 
    ios::sync_with_stdio(false);
    
    int n,m,tmp;
    cin >> n;
    while(n--) {
        cin >> tmp;
        s.insert(tmp);
    }    
    cin >> m;
    while(m--) {
        cin >> tmp;
        if (s.find(tmp) == s.end()) cout << 0 << "\n";
        else cout << 1 << "\n";
    }
}