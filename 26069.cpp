#include <iostream>
#include <vector>
#include <map>

using namespace std;

map <string,int> m;
int cnt = 1;
int chk[2002];
int ans = 0;

int main() 
{
    int n;
    cin >> n;
    m.insert({"ChongChong",0});
    chk[0] = 1;
    ans++;
    
    while(n--) {
        string a,b;
        cin >> a >> b;
        if (m.find(a) == m.end()) m.insert({a,cnt++});
        if (m.find(b) == m.end()) m.insert({b,cnt++});
        if (chk[m[a]] ^ chk[m[b]]) {
            ans++;
            chk[m[a]] = 1;
            chk[m[b]] = 1;
        }
    }

    printf("%d",ans);
}