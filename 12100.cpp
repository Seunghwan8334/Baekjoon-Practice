#include <stdio.h>
#include <vector>

using namespace std;

vector <int> v[22];

int n;
int ans = 0;

void getans(int a[22][22]) {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (a[i][j] > ans) ans = a[i][j];    
        }
    }
}

void addvec() {
    for (int i=1; i<=n; i++) {
        for (int j=0; j<n-1; j++) {
            if (v[i][j] == v[i][j+1]) {
                if (!v[i][j]) continue;
                v[i][j] *= 2;
                v[i].erase(v[i].begin()+j+1);
                v[i].push_back(0);
            }
        }
    }
}

void pushtop(int a[22][22],int cnt) {
    if (cnt==5) getans(a);
    else {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) v[j].push_back(a[i][j]);
        }
        addvec();
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) a[i][j] = v[j][i-1];
        }
        for (int i=1; i<=n; i++) v[i].clear();
        pushtop(a,cnt+1);
    }   
}

void pushbottom(int a[22][22], int cnt ) {
    if (cnt==5) getans(a);
    else {
        for (int i=n; i>=1; i--) {
            for (int j=1; j<=n; j++) v[j].push_back(a[i][j]);
        }
        addvec();
        for (int i=n; i>=1; i--) {
            for (int j=1; j<=n; j++) a[i][j] = v[j][i-1];
        }
    }
}

void pushleft(int a[22][22], int cnt ) {
    if (cnt==5) getans(a);
    else {
        for (int i=n; i>=1; i--) {
            for (int j=1; j<=n; j++) v[j].push_back(a[i][j]);
        }
        addvec();
        for (int i=n; i>=1; i--) {
            for (int j=1; j<=n; j++) a[i][j] = v[j][i-1];
        }
    }
}

int main() 
{
    scanf("%d",&n);

    int a[22][22];
    for (int i=1; i<=n; i++) 
        for (int j=1; j<=n; j++) 
            scanf("%d",&a[i][j]);

    pushtop(a,0);
    pushbottom(a,0);

    printf("%d",ans);
}   