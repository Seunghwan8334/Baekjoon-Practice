#include <stdio.h>

using namespace std;

int main() 
{
    char a[3];
    scanf("%s",a);

    float ans = 0;
    if (a[0] == 'A') ans += 4;
    else if (a[0] == 'B') ans += 3;
    else if (a[0] == 'C') ans += 2;
    else if (a[0] == 'D') ans += 1;
    else {
        printf("0.0");
        return 0;
    }

    if (a[1] == '+') ans += 0.3;
    else if (a[1] == '-') ans -= 0.3;

    printf("%.1f",ans);
}