using ll = long long;

class Solution {
public:
    long long countDistinct(long long n) {
    /*
        see key idea is ans += (digit[i] - 1) * 9^(no. of digit to the right of digit[i])
    */
        if(n < 10) return n;

        string s= to_string(n);

        int L = s.size();

        vector<ll> power_of_9(L+1,1);

        for(int i=1;i<=L;i++) power_of_9[i] = power_of_9[i-1]*9;

        ll ans=0;
        // taking all numbers with one less digit of L i.e 1 digit , 2 digit ... (L-1) digit

        for(int i=1;i<L;i++) ans += power_of_9[i];

        for(int i=0;i<L;i++){ // go digit by digit and check how many posiible with current prefix.
            ll d= s[i] - '0';

            if(d > 1) ans += (d-1)*power_of_9[L-1-i]; // L-1-i is lenght of right of i
            if(d==0) return ans;
        }
        return ans+1; // cs above we are finding less then n, if n doesn't have '0' it is also valid cnt
    }
};