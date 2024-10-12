#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map <string, int> m;
vector <string> v;

bool cmp (string a, string b) {
    if (m[a] == m[b]) {
        if (a.length() == b.length()) return a < b;
        else return a.length() > b.length();
    }
    else return m[a] > m[b];
};

int main() 
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;
    while (n--) {
        string tmp;
        cin >> tmp;
        if (tmp.length() >= k) {
            if (m.find(tmp) == m.end()) {
                m.insert({tmp,1});
                v.push_back(tmp);
            }
            else m[tmp]++;
        }
    }

    sort(v.begin(),v.end(),cmp);

    for (int i=0; i<v.size(); i++) cout << v[i] << "\n";
}