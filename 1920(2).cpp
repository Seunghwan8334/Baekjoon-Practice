#include <iostream>
#include <set>

using namespace std;

set <int> s;

int main() 
{   
    int n,m,tmp;
    scanf("%d",&n);
    while(n--) {
        scanf("%d",&tmp);
        s.insert(tmp);
    }    
    scanf("%d",&m);
    while(m--) {
        scanf("%d",&tmp);
        if (s.find(tmp) == s.end()) printf("0\n");
        else printf("1\n");
    }
}
