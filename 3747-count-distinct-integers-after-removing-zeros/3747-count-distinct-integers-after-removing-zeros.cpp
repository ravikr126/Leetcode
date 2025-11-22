class Solution {
public:
    long long countDistinct(long long n) {
        long long ans =0;
        string num = to_string(n);
        if(n<10) return n;
        int m = num.size();
        for(int i=1;i<=m-1;i++){
            ans=ans+(long long)pow(9,i);
        }
        // cout<<ans<<endl;
        int index=0;
        while(index<m && num[index]!='0'){
            long long digit=num[index]-'0';
            ans=ans+((digit-1)*(long long)pow(9,m-1-index));            
            if(index==m-1) ans++;
            index++;
        }
        return ans;
        
    }
};