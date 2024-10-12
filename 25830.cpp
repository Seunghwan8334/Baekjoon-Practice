#include <iostream>
#include <cstring>

using namespace std;

int main() 
{
    string timeA;
    cin >> timeA;
    string timeB = timeA+":00";
    timeA = "00:"+timeA;
    
    int HH = stoi(timeB.substr(0,2))-stoi(timeA.substr(0,2));
    int MM = stoi(timeB.substr(3,2))-stoi(timeA.substr(3,2));
    int SS = stoi(timeB.substr(6,2))-stoi(timeA.substr(6,2));
    if (SS < 0) {
        MM--;
        SS += 60;
    }
    if (MM < 0) {
        HH--;
        MM += 60;
    }

    printf("%02d:%02d:%02d",HH,MM,SS);
}