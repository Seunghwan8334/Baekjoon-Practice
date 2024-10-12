#include <stdio.h>
#include <vector>

using namespace std;

vector <int> ans;
vector <int> tmp;

struct s {
    int num;
    int index;
};

s a[100002];
int sum[100002];

bool cmp(s p1, s p2) {
    if (p1.num == p2.num) return p1.index < p2.index;
    return p1.num < p2.num;
};

int main() 
{
    int n;
    scanf("%d",&n);

    for (int i=1; i<=n; i++) {
        int tmp;
        scanf("%d",&tmp);    
        a[i] = {tmp,i};
        sum[i] += sum[i-1]+tmp;
    }

    sort(a+1,a+n+1,cmp);
    
    int p = 0;
    for (int i=1; i<=n; i++) {
        int num = a[i].num;
        int index = a[i].index;
        if (num > p) {
            while(!tmp.empty()) 
        }
    }
}