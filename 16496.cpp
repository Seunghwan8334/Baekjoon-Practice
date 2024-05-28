#include <iostream>
#include <vector>

using namespace std;

vector <string> v;

string a[1001];

int cmpstr(string p, string q) { 
    string tmp1 = p+q;
    string tmp2 = q+p;

    for (int i=0; i<p.length()+q.length(); i++) {
        if (tmp1[i] == tmp2[i]) continue;
        if (tmp1[i] > tmp2[i]) return 1;
        else return 0;
    }
    return 0;
}

int main() 
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];

    v.push_back(a[0]);
    for (int i=1; i<n; i++) {
        int chk = 1;
        for (int j=0; j<v.size(); j++) {
            if (cmpstr(a[i],v[j])) {
                v.insert(v.begin()+j,a[i]);
                chk = 0;
                break;
            }
        }
        if (chk) v.push_back(a[i]);
    }

    if (v.front()[0] == '0') {
        printf("0");
        return 0;
    }
    for (int i=0; i<v.size(); i++) cout << v[i];
}