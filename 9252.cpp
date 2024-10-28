#include <iostream>

using namespace std;

int arr[1003][1003];

int max(int a, int b, int c=0) {
    if (a > b && a > c) return a;
    if (b > c) return b;
    return c; 
}

int main() 
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string a,b;
    cin >> a >> b;
    int alen = a.length();
    int blen = b.length();

    for (int i=0; i<alen; i++) {
        for (int j=0; j<blen; j++) {
            if (a[i] == b[j]) arr[i][j] = 1;
        }
    }

    for (int i=0; i<alen; i++) {
        for (int j=0; j<blen; j++) {
            if (i == 0 && j == 0) continue;
            else if (i == 0) arr[i][j] = max(arr[i][j],arr[i][j-1]);
            else if (j == 0) arr[i][j] = max(arr[i][j],arr[i-1][j]);
            else arr[i][j] = max(arr[i][j]+arr[i-1][j-1],arr[i][j-1],arr[i-1][j]);
        }
    }

    int t = arr[alen-1][blen-1];
    cout << t << "\n";

    string ans = "";
    int y = alen-1;
    int x = blen-1;

    for (int i=alen-1; i>=0; i--) {
        if (t == 0) break;
        for (int j=blen-1; j>=0; j--) {
            if (t == 0) break;
            if (i > y || j > x) continue;

            if (i == 0 && j == 0) {
                ans.push_back(a[i]);
                t--;
                y = i-1;
                x = j-1;
            }
            else if (i == 0) {
                if (arr[i][j] == t && arr[i][j] > arr[i][j-1]) {
                    ans.push_back(a[i]);
                    t--;
                    y = i-1;
                    x = j-1;
                }
            }
            else if (j == 0) {
                if (arr[i][j] == t && arr[i][j] > arr[i-1][j]) {
                    ans.push_back(a[i]);
                    t--;
                    y = i-1;
                    x = j-1;
                }
            }
            else {
                if (arr[i][j] == t && arr[i][j] > arr[i-1][j] && arr[i][j] > arr[i][j-1]) {
                    ans.push_back(a[i]);
                    t--;
                    y = i-1;
                    x = j-1;
                }
            }
        }
    }

    for (int i=ans.length()-1; i>=0; i--) cout << ans[i];
}