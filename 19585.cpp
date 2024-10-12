#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

unordered_set <string> us;
vector <char> v[29][1002]; 
int p[29][1002];

int main() 
{
    int c,n;
    cin >> c >> n;
    for (int i=1; i<=c; i++) {
        string color;
        cin >> color;
        int tmp = 'z'-'a'+1;
        for (int j=0; j<color.length(); j++) {
            if (v[tmp][j].empty()) v[tmp][j].push_back(color[j]);
            tmp = color[j]-'a';
        }   
        p[tmp][color.length()-1] = 1;
    } 
    for (int i=1; i<=n; i++) {
        string tmp;
        cin >> tmp;
        us.insert(tmp);
    }

    int q;
    cin >> q;
    while (q--) {
        string str;
        cin >> str;

        int ans = 0;
        int tmp = 'z'-'a'+1;
        for (int i=0; i<str.length()-1; i++) {
            if (v[tmp][i].empty()) break;
            else {
                if (find(v[tmp][i].begin(),v[tmp][i].end(),str[i]) == v[tmp][i].end()) break;
                else {
                    if (p[tmp][i]) {
                        if (us.find(str.substr(i+1)) == us.end()) {
                            tmp = str[i]-'a';
                            continue;
                        }
                        else {
                            ans = 1;
                            break;
                        }
                    }
                }
            }
        }

        if (ans) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
}