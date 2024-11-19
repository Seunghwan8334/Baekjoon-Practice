#include <iostream>
#include <vector>
#include <string>

std::vector <char> v;

int main() 
{
    std::string a,b;
    std::cin>>a>>b;
    for (int i=0; i<a.length(); i++) {
        v.push_back(a[i]);
        if (i+1>=b.length() && v.back() == b[b.length()-1]) {
            int same = 1;
            for (int j=0; j<b.length(); j++) {
                if (b[j] != v[v.size()-b.length()+j]) same = 0;
            }
            if (same) {
                for (int k=0; k<b.length(); k++) v.pop_back();
            }
        }
    }
    if (v.empty()) std::cout<< "FRULA";
    else {
        for (char i : v) std::cout << i;
    }
}