#include <iostream>
#include <utility>

using namespace std;

int z[21][300003];
int m[21][300003];

pair <int,int> mzsum(int p,int q,int begin, int end, int cd, int cl) {
    if (p <= begin && end <= q) return make_pair(z[cd][cl],m[cd][cl]);
    int mid = (begin+end)/2;
    if (q <= mid) return mzsum(p,q,begin,mid,cd+1,cl*2);
    else if (mid < p) return mzsum(p,q,mid+1,end,cd+1,cl*2+1);
    else {
        pair <int,int> p1 = mzsum(p,q,begin,mid,cd+1,cl*2);
        pair <int,int> p2 = mzsum(p,q,mid+1,end,cd+1,cl*2+1);
        return make_pair(p1.first+p2.first,p1.second+p2.second);
    }
}

int main() 
{
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false); 
    int n,k;
    while (cin >> n >> k){
        int tl=1;
        int td=0;
        while (tl <= n) {
            tl *= 2;
            td++;
        }
    
        for (int i=1; i<=n; i++) {
            int tmp;
            cin >> tmp;
            if (tmp < 0) m[td][i] = 1;
            if (tmp == 0) z[td][i] = 1;
        }
    
        for (int i=td-1; i>=0; i--) {
            for (int j=0; j<tl; j++) {
                z[i][j] = z[i+1][j*2]+z[i+1][j*2+1];
                m[i][j] = m[i+1][j*2]+m[i+1][j*2+1];
            }
        }
    
        while(k--) {
            char A;
            int p,q;
            cin >> A >> p >> q;
            if (A=='C') {
                m[td][p] = 0;
                z[td][p] = 0;
                if (q < 0) m[td][p] = 1;
                else if (q==0) z[td][p] = 1;
                
                int tc = p/2;
                for (int i=td-1; i>=0; i--) {
                    m[i][tc] = m[i+1][tc*2]+m[i+1][tc*2+1];
                    z[i][tc] = z[i+1][tc*2]+z[i+1][tc*2+1];
                    tc /= 2;
                }
            }
            else {
                pair <int,int> psum = mzsum(p,q,0,tl-1,0,0); 
                if (psum.first) cout << "0";
                else if (psum.second%2==0) cout << "+";
                else cout << "-";
            }
        }
        for (int i=0; i<=td; i++) {
            for (int j=0; j<tl; j++) {
                z[i][j] = 0;
                m[i][j] = 0;
            }
        }
        cout << "\n";
    }
}
