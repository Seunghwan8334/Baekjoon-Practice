    #include <stdio.h>
    #define MOD 1000000007 

    int top[4000002];
    int bot[4000002];
    int cnt[4000002];
    int is_prime[4000002];

    int prime(int x) {
        if (x == 1) return 0;
        for (int i=2; i*i<=x; i++) {
            if (x%i == 0) return 0;
        }
        return 1;
    }

    long long int power(int NUM, int CNT) {
        if (CNT == 0) return 1;
        long long int half = power(NUM,CNT/2);
        if (CNT%2 == 1) return (NUM*(half*half)%MOD)%MOD;
        else return (half*half)%MOD;
    }

    int main() 
    {
        int n,k;
        scanf("%d %d",&n,&k);

        for (int i=1; i<=n; i++) top[i]++;
        for (int i=1; i<=k; i++) bot[i]++;
        for (int i=1; i<=n-k; i++) bot[i]++;
        for (int i=1; i<=n; i++) {
            if (prime(i)) is_prime[i] = 1;
        }

        for (int i=n; i>=4; i--) {
            if (top[i] == 0) continue;
            if (is_prime[i]) continue;

            int num = i;
            for (int j=2; j*j<=i; j++) {
                if (num%j == 0) {
                    int tmpcnt = 0;
                    while(num%j == 0) {
                        tmpcnt++;
                        num /= j;
                    }
                    top[j] += top[i]*tmpcnt;
                }
            }
            top[num]++;
            top[i] = 0;
        }

        for (int i=n; i>=4; i--) {
            if (bot[i] == 0) continue;
            if (is_prime[i]) continue;

            int num = i;
            for (int j=2; j*j<=i; j++) {
                if (num%j == 0) {
                    int tmpcnt = 0;
                    while(num%j == 0) {
                        tmpcnt++;
                        num /= j;
                    }
                    bot[j] += bot[i]*tmpcnt;
                }
            }
            bot[num]++;
            bot[i] = 0;
        }

        long long int ans = 1;
        for (int i=2; i<=n; i++) cnt[i] = top[i]-bot[i];
        for (int i=2; i<=n; i++) {
            if (cnt[i] == 0) continue;
            long long int tmp = power(i,cnt[i]);
            ans *= tmp;
            ans %= MOD;
        }
        printf("%lld",ans);
    }