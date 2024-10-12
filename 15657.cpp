#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v;

int n,m,a[10];

void prt() {
    for (int i=0; i<v.size(); i++) printf("%d ",v[i]);
    printf("\n");
}

void f(int i, int cnt) {
    if (cnt == m) {
        prt();
        return;
    }
    for (int j=i; j<n; j++) {
        v.push_back(a[j]);
        f(j,cnt+1);
        v.pop_back();
    }
}

int main() 
{
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    sort(a,a+n);
    f(0, 0);
}