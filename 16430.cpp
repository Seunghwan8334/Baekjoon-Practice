#include <stdio.h>
int main() 
{
    int A,B;
    scanf("%d %d",&A,&B);
    int b = A>B?A:B;
    int s = A>B?B:A;
    while(s) {
        int tmp = s;
        s = b%s;
        b = tmp;
    }
    A /= b;
    B /= b;
    printf("%d %d",A,B);
}