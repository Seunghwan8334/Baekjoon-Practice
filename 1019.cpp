#include <iostream>
#include <cmath>

using namespace std;

int ans[11]; // count for each number 
int tmp[11]; // count for each number 
int sva[11]; // count for each number under that digit

void addtmp(int x) {
    for (int i=0; i<=9; i++) ans[i] += tmp[i]*x;
}
void addans(int x, int from, int to) {
    for (int i=from; i<=to; i++) ans[i] += x;
}

int main() 
{
    string n;
    cin >> n;
    int len = n.length();
    
    for (int i=1; i<=len; i++) sva[i] = sva[i-1]*10+pow(10,i-1);
    for (int i=0; i<len; i++) tmp[n[i]-'0']++;

    for (int i=1; i<=len; i++) { 
        int num = n[len-i]-'0';
        ans[num]++; // adding the biggest number 1 by 1
        tmp[num]--; 

        addtmp(pow(10,i-1)*num); 
        addans(sva[i-1]*num,0,9); 
        addans(pow(10,i-1),0,num-1); 
    }
    
    ans[0]-= len;
    for (int i=2; i<=len; i++) ans[0]-=(i-1)*9*pow(10,len-i);
    
    for (int i=0; i<=9; i++) cout << ans[i] << " ";
}
