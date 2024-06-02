#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <int> v;

long long int cnt(long long int x) {
    int len=1;
    while (true) {
        if ((long long)pow(2,len) > x) break;
        len++;
    }

    long long int one = 0;
    for (int i=len-1; i>=0; i--) {
        if (x>=(long long)pow(2,i)) {
            x -= (long long)pow(2,i);
            v.push_back(1);
            one += 1;
        }
        else v.push_back(0);
    }    
    long long int sum = 0;
    sum += one;
    for (int i=v.size()-1; i>=0; i--) {
        int digit = v.size()-i;
        if (v[i]) {
            one -= 1;
            sum += (long long)pow(2,digit-1)*one+(long long)((long long)pow(2,digit-1)*(digit-1))/2;
        }
    }
    v.clear();
    return sum;
}

int main() 
{
    long long int a,b;
    cin >> a >> b;
    cout << cnt(b)-cnt(a-1);
}