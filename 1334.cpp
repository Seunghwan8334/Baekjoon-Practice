#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string n;
    cin >> n;
    string str_n;

    long long int num = 0;
    if (n.length()%2 == 1) {
        str_n = n.substr(0,n.length()/2+1);
        int int_n = stoi(str_n);
        string str1 = to_string(int_n+1);
        string str2 = to_string(int_n);
        if (str1.length() > str2.length()) {
            string ans = to_string(int_n+1);
            for (int i=0; i<ans.length()-1; i++) cout << ans[i];
            for (int i=ans.length()-2; i>=0; i--) cout << ans[i];
        }
        else {
            string ans = to_string(int_n+1);
            for (int i=0; i<ans.length(); i++) cout << ans[i];
            for (int i=ans.length()-2; i>=0; i--) cout << ans[i];
        } 
    }
    else {
        str_n = n.substr(0,n.length()/2);
        int int_n = stoi(str_n);
        string str1 = to_string(int_n+1);
        string str2 = to_string(int_n);
        if (str1.length() > str2.length()) {
            string ans = to_string(int_n+1);
            for (int i=0; i<ans.length()-1; i++) cout << ans[i];
            for (int i=ans.length()-1; i>=0; i--) cout << ans[i];
        }
        else {
            string ans = to_string(int_n+1);
            for (int i=0; i<ans.length(); i++) cout << ans[i];
            for (int i=ans.length()-1; i>=0; i--) cout << ans[i];
        } 
    }
}