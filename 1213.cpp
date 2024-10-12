#include <iostream>
#include <vector>

using namespace std;

vector <char> odd;
vector <char> even;

int cnt[202];

int main() 
{
    string a;
    cin >> a;
    for (int i=0; i<a.length(); i++) {
        cnt[a[i]]++;
    }

    for (int i='A'; i<='Z'; i++) {
        if (cnt[i] > 0) {
            if (cnt[i]%2) {
                even.push_back(i);
                odd.push_back(i);
            }
            else even.push_back(i);
        }
    }

    if (odd.size() > 1) cout << "I\'m Sorry Hansoo";
    else {
        for (int i=0; i<even.size(); i++) {
            for (int j=1; j<=cnt[even[i]]/2; j++) cout << even[i];
        }
        if (odd.size() == 1) cout << odd[0];  
        for (int i=even.size()-1; i>=0; i--) {
            for (int j=1; j<=cnt[even[i]]/2; j++) cout << even[i];
        }
    }
}