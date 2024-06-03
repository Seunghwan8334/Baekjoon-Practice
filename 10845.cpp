#include <iostream>
#include <queue>

using namespace std;

queue <int> q;

int main() 
{
    int n;
    cin >> n;

    while(n--) {
        string a;
        cin >> a;
        if (a == "push") {
            int tmp;
            cin >> tmp;
            q.push(tmp);
        }
        else if (a == "pop") {
            if (q.empty()) printf("-1\n");
            else {
                printf("%d\n",q.front());
                q.pop();
            }
        }
        else if (a == "size") printf("%d\n",q.size());
        else if (a == "empty") printf("%d\n",q.empty());
        else if (a == "front") {
            if (q.empty()) printf("-1\n");
            else printf("%d\n",q.front());
        }
        else if (a == "back") {
            if (q.empty()) printf("-1\n");
            else printf("%d\n",q.back());
        }
    }
}