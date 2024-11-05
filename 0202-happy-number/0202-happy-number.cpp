class Solution {
public:
    int solve(int n){
        int x=0;
        while(n>0){
            int c=n%10;
            x=x+c*c;
            n=n/10;
        }
        return x;
    }
    bool isHappy(int n) {
        unordered_set<int> sett;
        while(n!=1 && !sett.count(n)){
            sett.insert(n);
            n=solve(n);
            cout<<n<<" ";
        }
        if(n==1)return true;
        return false;
    }
};