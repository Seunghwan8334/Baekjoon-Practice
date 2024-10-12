#include <iostream>

using namespace std;

int main() 
{
    string a;
    int b,c;
    while(cin >> a >> b >> c) {
        if (a == "#" && b == 0 && c == 0) break;
        if (b > 17 || c >= 80) cout << a << " Senior" << "\n";
        else cout << a << " Junior" << "\n";
    }
}