#include <stdio.h>

long long int graph[20];

int main() 
{
    long long int n,w;
    scanf("%lld %lld",&n,&w);

    for (int i=1; i<=n; i++) scanf("%lld",&graph[i]);
    
    long long int money = w;
    long long int coin = 0;

    for (int i=1; i<n; i++) {
        if (graph[i] < graph[i+1]) {
            money += coin*graph[i];
            coin = money/graph[i];
            money %= graph[i];
        }
        else {
            money += coin*graph[i];
            coin = 0;
        }
    }
    money += graph[n]*coin;
    printf("%lld",money);
}