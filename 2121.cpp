#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

set <pair<int,int>> s;
vector <pair<int,int>> v;

int main() 
{
    int N;
    scanf("%d",&N);

    int A,B;
    scanf("%d %d",&A,&B);

    while(N--) {
        int a,b;
        scanf("%d %d",&a,&b);
        v.push_back({a,b});
        s.insert({a,b});
    }

    int ans = 0;
    for (int i=0; i<v.size(); i++) {
        int a = v[i].first;
        int b = v[i].second;

        if (s.find({a,b+B}) != s.end() && s.find({a+A,b}) != s.end() && s.find({a+A,b+B}) != s.end()) ans++;
    }
    printf("%d",ans);
}