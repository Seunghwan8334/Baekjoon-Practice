#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string str[15002];
int strcnt = 1;

vector <int> v[15002];

bool cmp(int p1, int p2) {
    return str[p1] < str[p2];
};

void f(int x, int cnt) {
    for (int i=0; i<cnt; i++) cout << "--";
    cout << str[x] << "\n";
    for (int i=0; i<v[x].size(); i++) {
        int num = v[x][i];
        f(num,cnt+1);
    }
}

int main() 
{
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int tmp = 0;
        while(n--) {
            string a;
            cin >> a;

            int founded = 0;
            for (int i=0; i<v[tmp].size(); i++) {
                int num = v[tmp][i];
                if (str[num] == a) {
                    founded = 1;
                    tmp = num;
                    break;
                }
            }

            if (!founded) {
                v[tmp].push_back(strcnt);
                str[strcnt] = a;
                tmp = strcnt++;
            }
        }
    }

    for (int i=0; i<strcnt; i++) sort(v[i].begin(),v[i].end(),cmp);
    for (int i=0; i<v[0].size(); i++) f(v[0][i],0);
}