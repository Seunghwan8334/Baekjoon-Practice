#include <iostream>

using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;

    int ans[4002][4002];
    for (int i=0; i<a.length(); i++) {
        if (a[i*2] == 'A' || a[i*2] == 'E' || a[i*2] == 'F' || a[i*2] == 'H' || a[i*2] == 'I') ans[a.length()*2-1][i*2] = 3;
        else if (a[i*2] == 'B' || a[i*2] == 'D' || a[i*2] == 'G' || a[i*2] == 'J' || a[i*2] == 'K' ||
         a[i*2] == 'M' || a[i*2] == 'N' || a[i*2] == 'P' || a[i*2] == 'Q' || a[i*2] == 'R' || a[i*2] == 'T' 
         || a[i*2] == 'X' || a[i*2] == 'Y') ans[a.length()*2-1][i*2] = 2;
        else ans[a.length()*2-1][i*2] = 1;

        if (b[i*2+1] == 'A' || b[i*2+1] == 'E' || b[i*2+1] == 'F' || b[i*2+1] == 'H' || b[i*2+1] == 'I') ans[a.length()*2-1][i*2+1] = 3;
        else if (b[i*2+1] == 'B' || b[i*2+1] == 'D' || b[i*2+1] == 'G' || b[i*2+1] == 'J' || b[i*2+1] == 'K' ||
         b[i*2+1] == 'M' || b[i*2+1] == 'N' || b[i*2+1] == 'P' || b[i*2+1] == 'Q' || b[i*2+1] == 'R' || b[i*2+1] == 'T' 
         || b[i*2+1] == 'X' || b[i*2+1] == 'Y') ans[a.length()*2-1][i*2+1] = 2;
        else ans[a.length()*2-1][i*2+1] = 1;
    }

    for (int i=a.length()*2-2; i>=1; i++) {
        for (int j=0; j<=i; j++) {
            ans[i][j] = ans[i+1][j]+ans[i+1][j+1];
            ans[i][j] %= 10;
        }
    }

    cout << ans[1][0] << ans[1][1];
}