#include <iostream>

using namespace std;

int main() 
{
    string s;
    cin >> s;

    for (int i=1; i<=5; i++) {
        for (int j=0; j<s.length(); j++) {
            string tmp;
            if ((j+1)%3 == 0) tmp = "*";
            else tmp = "#"; 

            if (i == 3) {
                if (j%3 == 0 && j > 0) cout << "*." << s[j] << ".";
                else cout << tmp+"."+s[j]+".";
            }
            else if (i%2) cout << ".."+tmp+".";
            else cout << "."+tmp+"."+tmp;
        }
        if (i == 3) {
            if ((s.length())%3 == 0) cout << "*";
            else cout << "#";
        }
        else cout << ".";
        
        cout << "\n";
    }
}