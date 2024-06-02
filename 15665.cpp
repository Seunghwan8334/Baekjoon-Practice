#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v;

int n,m,len=0;
int arr[10001];
int chk[10001];

void ans(int x, int cnt) {
    if (cnt == m) {
        for (int i=0; i<v.size(); i++) printf("%d ",v[i]);
        printf("\n");
        return;
    }
    for (int i=0; i<len; i++) {
        v.push_back(arr[i]);
        ans(i,cnt+1);
        v.pop_back();
    }
} 

int main() 
{
    scanf("%d %d",&n,&m);

    for (int i=0; i<n; i++) {
        scanf("%d",&arr[len]);
        if (!chk[arr[len]]) chk[arr[len++]]++; 
    }

    sort(arr,arr+len);

    ans(0,0);
}