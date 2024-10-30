#include <iostream>
#include <map>

std::map <int,int> M;

int main() 
{
    int n,m,tmp;
    scanf("%d",&n);
    while(n--) {
        scanf("%d",&tmp);
        if (M.find(tmp) == M.end()) M.insert({tmp,1});
        else M[tmp]++;
    }
    scanf("%d",&m);
    while(m--) {
        scanf("%d",&tmp);
        if (M.find(tmp) == M.end()) printf("0 ");
        else printf("%d ",M[tmp]);
    }
}
