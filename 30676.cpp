#include <stdio.h>
int main() 
{
    int n;
    scanf("%d",&n);
    if (620 <= n && n <= 780) printf("Red");
    else if (590 <= n && n < 620) printf("Orange");
    else if (570 <= n && n < 590) printf("Yellow");
    else if (495 <= n && n < 570) printf("Green");
    else if (450 <= n && n < 495) printf("Blue");
    else if (425 <= n && n < 450) printf("Indigo");
    else if (380 <= n && n < 425) printf("Violet");
}