#include <stdio.h>
int main() 
{
    int A,B,N;
    scanf("%d %d %d",&A,&B,&N);
    for (int i=1; i<=N; i++) {
        A %= B;
        A *= 10;
    }
    printf("%d",A/B);
}