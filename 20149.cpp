#include <stdio.h>

int x1,y1,x2,y2,x3,y3,x4,y4;

double L1(int x) {
    return ((x2-x1)/(y2-y1))*x+y1-((x2-x1)/(y2-y1))*x1;
}

double L2(int x) {
    return ((x4-x3)/(y4-y3))*x+y3-((x4-x3)/(y4-y3))*x3;
}

int main() 
{  
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    scanf("%d %d %d %d",&x3,&y3,&x4,&y4);
    if (x1>x2) {
        int tmpx = x1;
        int tmpy = y1;
        x1 = x2;
        y1 = y2;
        x2 = tmpx;
        y2 = tmpy;
    }
    if (x3>x4) {
        int tmpx = x3;
        int tmpy = y3;
        x3 = x4;
        y3 = y4;
        x4 = tmpx;
        y4 = tmpy;
    }
    int ans = 0;
    for (int i=x1<x3?x1:x3; i<=x2<x4?x4:x2; i++) {
        if (x1 <= i && i <= x2 && x3 <= i && u <= x4) {
            if (L1(i) ==)
        }
    }
}