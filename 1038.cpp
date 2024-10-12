#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long int> ans;
long long int tmp = 0;

void loop(int x) {
    for (int i=x; i>=0; i--) {
        tmp /= 10;
        tmp *= 10;
        tmp += i;
        ans.push_back(tmp);
        tmp *= 10;
        loop(i-1);
        tmp /= 10;
    }
}

int main() 
{
    int n;
    scanf("%d",&n);
    loop(9);
    sort(ans.begin(),ans.end());
    if (n > ans.size()-1) printf("-1"); 
    else printf("%lld",ans[n]);
}