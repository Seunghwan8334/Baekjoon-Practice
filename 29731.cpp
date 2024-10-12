#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <string> list;

int main() 
{
    list.push_back("Never gonna give you up");
    list.push_back("Never gonna let you down");
    list.push_back("Never gonna run around and desert you");
    list.push_back("Never gonna make you cry");
    list.push_back("Never gonna say goodbye");
    list.push_back("Never gonna tell a lie and hurt you");
    list.push_back("Never gonna stop");

    int n;
    cin >> n;
    cin.ignore();
    int cnt = 0;
    while(n--) {
        string str;
        getline(cin, str);
        if (find(list.begin(),list.end(),str) == list.end()) cnt++;
    }

    if (cnt) cout << "Yes";
    else cout << "No";
}