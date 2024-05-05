#include <iostream>
#include <cmath>

using namespace std;

int ans[11];
int tmp[11];

int sva[11];

void addtmp(int x) {
    for (int i=0; i<=9; i++) ans[i] += tmp[i]*x;
}
void addsva(int x) {
    for (int i=0; i<=9; i++) ans[i] += x;
}

int main() 
{
    string n;
    cin >> n;
    int len = n.length();
    
    sva[1] = 1;
    for (int i=2; i<=len; i++) sva[i] = sva[i-1]*10+pow(10,i-1);

    for (int i=0; i<len; i++) tmp[n[i]-'0']++;

    for (int i=1; i<=len; i++) {
        int num = n[len-i]-'0';
        tmp[num]--;

        if (i==1) {
            for (int j=0; j<=num; j++) {
                ans[j]++;
                addtmp(1);
            }
        }
        else {
            for (int j=0; j<num; j++) {
                addtmp(pow(10,i-1));
                ans[j] += pow(10,i-1);
                addsva(sva[i-1]);
            }
        }
    }
    
    for (int i=2; i<=len; i++) {
        ans[0]-=(i-1)*9*pow(10,len-i);
    }
    
    ans[0]-= len;
    
    for (int i=0; i<=9; i++) cout << ans[i] << " ";
}