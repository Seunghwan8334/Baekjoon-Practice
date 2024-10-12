#include <iostream>
#include <map>

using namespace std;

map <string, int> m;

int pn = 0;
int parent[200003];
int ans[200003];

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    ans[b] += ans[a];
    parent[a] = b;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n,pn=0;
        cin >> n;

        while(n--) {
            string a,b;
            cin >> a >> b;

            if (m.find(a) == m.end()) {
                parent[pn] = pn;
                ans[pn] = 1;
                m.insert({a,pn++});
            }
            if (m.find(b) == m.end()) {
                parent[pn] = pn;
                ans[pn] = 1;
                m.insert({b,pn++});
            }
            
            parent[m[a]] = Find(m[a]);
            parent[m[b]] = Find(m[b]);

            if (parent[m[a]] == parent[m[b]]) cout << ans[parent[m[a]]] << "\n";
            else {
                Union(parent[m[a]],parent[m[b]]);
                cout << ans[parent[m[b]]] << "\n";
            }
        }

        m.clear();
    }
}