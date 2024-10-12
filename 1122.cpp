#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

queue <pair<int,int>> q;
vector <int> v;

int ans[200003];

int main() 
{
    int A,B,K;
    scanf("%d %d %d",&A,&B,&K);
    int std = A+B;
    for (int i=0; i<=200000; i++) ans[i] = -1;
    for (int i=0; i<=A+B; i++) v.push_back(i);

    ans[A] = 0;
    q.push({A,0});
    v.erase(find(v.begin(), v.end(), A));
    while(!q.empty()) {
        int num1 = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        int mn,mx,num2=std-num1;
        if (num1 > K) mn = num1-K;
        else mn = K-num1;
        if (num2 > K) mx = num1+K;
        else mx = num1+num2-(K-num2); 

        int it = lower_bound(v.begin(),v.end(),mn)-v.begin();
        while(v.begin()+it != v.end()) {
            if (v[it] > mx) break;
            ans[v[it]] = cnt+1;
            q.push({v[it],cnt+1});
            v.erase(v.begin()+it);
        }
    }

    printf("%d",ans[0]);
}












