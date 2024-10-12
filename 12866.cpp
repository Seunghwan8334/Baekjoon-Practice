#include <iostream>
#include <map>
#define tmp 1000000007

using namespace std;

map <char, long long int> m;

int main() 
{
    int n;
    cin >> n;

    string a;
    cin >> a;

    m.insert({'A',0});
    m.insert({'C',0});
    m.insert({'G',0});
    m.insert({'T',0});

    for (int i=0; i<a.length(); i++) m[a[i]]++;
    
    cout << (((m['A']%tmp*m['C']%tmp)%tmp*m['G']%tmp)%tmp*m['T']%tmp)%tmp;
}