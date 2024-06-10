#include <iostream>
#include <string>
#include <set>

using namespace std;

struct cmp {
    bool operator()(const string& p1, const string& p2) const {
        if (p1.length() == p2.length()) return p1 < p2;
        else return p1.length() < p2.length();
    }
};

set <string,cmp> ans;

void f(string x) {
    if (x.length() > 7) return;
    if (x[0] != '0') ans.insert(x);
    for (int i=0; i<=9; i++) {
        f(to_string(i)+x);
        f(x+to_string(i));
    }
}

int main() 
{
    f("666");

    int n;
    cin >> n;
    cout << *next(ans.begin(), n - 1);
}