#include <stdio.h>
#include <math.h>

using namespace std;

int td = 0;
int tree[20][200001];
int lazy[20][200001];

void propagate(int begin, int end, int cd, int cl) {
    if (lazy[cd][cl]) {
        tree[cd][cl] = pow(2,td-cd) - tree[cd][cl]; 
        if (cd < td) {
            lazy[cd+1][cl*2] ^= 1;
            lazy[cd+1][cl*2+1] ^= 1;
        }
        lazy[cd][cl] = 0; 
    }
}

void update(int l, int r, int begin, int end, int cd, int cl) {
    propagate(begin, end, cd,cl);
    if (begin > r || end < l) return; 
    if (l <= begin && end <= r) { 
        lazy[cd][cl] ^= 1;
        propagate(begin, end, cd, cl);
        return;
    }
    int mid = (begin+end)/2;
    update(l, r, begin, mid, cd+1, cl*2);
    update(l, r, mid+1, end, cd+1, cl*2+1);
    tree[cd][cl] = tree[cd+1][cl*2] + tree[cd+1][cl*2+1];
}

int addtree(int l, int r, int begin, int end, int cd, int cl) {
    propagate(begin, end, cd, cl);
    if (begin > r || end < l) return 0; 
    if (l <= begin && end <= r) return tree[cd][cl];
    int mid = (begin+end)/2;
    return addtree(l, r, begin, mid, cd+1, cl*2) + addtree(l, r, mid+1, end, cd+1, cl*2+1);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    while (pow(2, td) <= n) td++;
    while (m--) {
        int o, s, t;
        scanf("%d %d %d", &o, &s, &t);

        if (o) printf("%d\n", addtree(s-1, t-1, 0, pow(2,td)-1, 0, 0));
        else update(s-1, t-1, 0, pow(2,td)-1, 0, 0);
    }
}
