#include <stdio.h>
#include <algorithm>

using namespace std;

struct s {
    int a;
    int b;
    int c;
}; 

int parent[1000002];
struct s arr[1000002];

bool cmp (s p1, s p2) {
    return p1.c < p2.c;
};

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    parent[find(a)] = find(b);
}

int main() 
{
    int n,m;
    scanf("%d %d",&n,&m);

    for (int i=0; i<m; i++) scanf("%d %d %d",&arr[i].a,&arr[i].b,&arr[i].c);
    sort(arr,arr+m,cmp);

    for (int i=1; i<=n; i++) parent[i] = i;

    int mx;
    int ans = 0;
    for (int i=0; i<m; i++) {
        int a = arr[i].a;
        int b = arr[i].b;
        int c = arr[i].c;

        if (find(a) != find(b)) {
            merge(a,b);
            ans += c;
            mx = c;
        }
    }

    printf("%d",ans-mx);
}