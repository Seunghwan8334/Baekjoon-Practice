#include <iostream>

using namespace std;

int main() 
{
    while (true) { 
        int a,b,c;
        cin >> a >> b >> c;
        if (a+b+c == 0) break;
        
        if (a+b <= c || b+c <= a || a+c <= b) cout << "Invalid\n";
        else if (a == b && b == c) cout << "Equilateral\n";
        else if (a != b && b != c && a != c) cout << "Scalene\n";
        else cout << "Isosceles\n";
    }
}