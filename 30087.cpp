#include <iostream>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    while(n--) {
        string tmp;
        cin >> tmp;
        if (tmp == "Algorithm") cout << "204\n";
        else if (tmp == "DataAnalysis") cout << "207\n";
        else if (tmp == "ArtificialIntelligence") cout << "302\n";
        else if (tmp == "CyberSecurity") cout << "B101\n";
        else if (tmp == "Network") cout << "303\n";
        else if (tmp == "Startup") cout << "501\n";
        else if (tmp == "TestStrategy") cout << "105\n";
    }
}