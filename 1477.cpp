#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int a[52];
int cnt[52];
vector <int> tmp;

int main() 
{
    int N,M,L;
    scanf("%d %d %d",&N,&M,&L);
    for (int i=0; i<N; i++) scanf("%d",&a[i]);

    sort(a,a+N);
    tmp.push_back(a[0]);
    for (int i=1; i<N; i++) tmp.push_back(a[i]-a[i-1]);
    tmp.push_back(L-a[N-1]);

    for (int i=0; i<tmp.size(); i++) cnt[i] = 1;

    while(M--) {
        int mxn = 0;
        int mxi = 0;
        for (int i=0; i<tmp.size(); i++) {
            if ((tmp[i]+cnt[i]-1)/cnt[i] > mxn) {
                mxn = (tmp[i]+cnt[i]-1)/cnt[i];
                mxi = i;
            }
        }
        cnt[mxi]++;
    }
    
    int mxn = 0;
    for (int i=0; i<tmp.size(); i++) {
        if ((tmp[i]+cnt[i]-1)/cnt[i] > mxn) mxn = (tmp[i]+cnt[i]-1)/cnt[i];
    }
    printf("%d",mxn);
}