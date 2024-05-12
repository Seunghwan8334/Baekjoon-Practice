#include <stdio.h>
#include <math.h>

using namespace std;

int chk[10000001];
int num[10000001];

int fmn(int x) {
    if (chk[x]==2) return num[x];
    chk[x]++;
    return num[x] = min(fmn(num[x]),x);
}

int main() 
{
    int a,b,k;
    scanf("%d %d %d",&a,&b,&k);
    
    for (int i=1; i<=5000000; i++) {
        int sum = 0;
        int tmp = i;
        while(tmp) {
            sum += pow(tmp%10,k);
            tmp /= 10;
        }
        num[i] = sum;
    }
    
    for (int i=1; i<=5000000; i++) {
        if (chk[i]) continue;
        num[i] = min(i,fmn(i));
    }
    long long int ans = 0;
    for (int i=a; i<=b; i++) ans += num[i];
    printf("%lld",ans);
}