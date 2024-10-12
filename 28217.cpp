#include <stdio.h>

int A1[12][12];
int A2[12][12];
int A3[12][12];
int B[12][12];

int main() 
{
    int n,ans=200000000;
    scanf("%d",&n);

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) scanf("%d",&A1[i][j]);
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) scanf("%d",&B[i][j]);
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) A2[n-i+1+j-1][j] = A1[i][i-j+1];
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) A3[n-i+1+j-1][j] = A2[i][i-j+1];
    }
    int A1B = 0;
    int RA1B = 0;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            A1B += A1[i][j]^B[i][j];
            RA1B += A1[i][i-j+1]^B[i][j];
        }
    }
    if (A1B < ans) ans = A1B;
    if (RA1B < ans) ans = RA1B;

    int A2B = 0;
    int RA2B = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            A2B += A2[i][j]^B[i][j];
            RA2B += A2[i][i-j+1]^B[i][j];
        }
    }
    if (A2B < ans) ans = A2B;
    if (RA2B < ans) ans = RA2B;

    int A3B = 0;
    int RA3B = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            A3B += A3[i][j]^B[i][j];
            RA3B += A3[i][i-j+1]^B[i][j];
        }
    }
    if (A3B < ans) ans = A3B;
    if (RA3B < ans) ans = RA3B;

    printf("%d",ans);
}