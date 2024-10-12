#include <iostream>
#include <deque>

using namespace std;

deque <char> ans;

int main() 
{
    string a;
    cin >> a;
    ans.push_back(a[0]);

    for (int i=1; i<a.length(); i++) {
        if (a[i] <= ans.front()) ans.push_front(a[i]);
        else ans.push_back(a[i]);
    }
    while(!ans.empty()) {
        cout << ans.front();
        ans.pop_front();
    }
}