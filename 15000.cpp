#include <iostream>
#include <cctype>

using namespace std;

int main() 
{
    string a;
    cin >> a;
    int cnt = 0;
    for (char i : a) {
        if (islower(i)) {
            a[cnt] = toupper(i);
        }
        cnt++;
    }
    cout << a;
}