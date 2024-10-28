#include <iostream>

using namespace std;

int a[102][102];
int b[102][102];
int c[102][102];

int main() 
{
    int n,m,k;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) cin >> a[i][j];
    }
    cin >> m >> k;
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=k; j++) cin >> b[i][j];
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            for (int t=1; t<=m; t++) c[i][j] += a[i][t]*b[t][j];
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) cout << c[i][j] << " ";
        cout << "\n";
    }
}