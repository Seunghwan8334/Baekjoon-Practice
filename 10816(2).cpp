#include <iostream>
#include <map>

std::map <int,int> M;

int main() 
{
    int n;
    scanf("%d",&n);
    while(n--) {
        int tmp;
        scanf("%d",&tmp);
        if (M.find(tmp) == M.end()) M.insert({tmp,1});
        else M[tmp]++;
    }
    int m;
    scanf("%d",&m);
    while(m--) {
        int tmp;
        scanf("%d",&tmp);
        if (M.find(tmp) == M.end()) printf("0 ");
        else printf("%d ",M[tmp]);
    }
}