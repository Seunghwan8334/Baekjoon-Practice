#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
    int arr[3];
    for (int i=0; i<3; i++) cin >> arr[i];
    sort(arr,arr+3);
    if (arr[2] < arr[0]+arr[1]) cout << arr[0]+arr[1]+arr[2];
    else cout << arr[0]*2+arr[1]*2-1;
}