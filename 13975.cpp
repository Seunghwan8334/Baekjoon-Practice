#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue <long long int,vector<long long int>,greater<long long int>> pq;

int main() 
{
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        long long int ans=0;
        scanf("%d",&n);
        for (int i=0; i<n; i++) {
            int num;
            scanf("%d",&num);
            pq.push(num);
        }
        
        while(pq.size()>1) {
            long long int num1 = pq.top();
            pq.pop();
            long long int num2 = pq.top();
            pq.pop();

            pq.push(num1+num2);
            ans += num1+num2;
        }
        pq.pop();
        printf("%lld\n",ans);
    }
}