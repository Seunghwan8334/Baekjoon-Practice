#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v;

int chk[200002];

int main() 
{
    int n,c;
    cin >> n >> c;
    
    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(),v.end());

    
}