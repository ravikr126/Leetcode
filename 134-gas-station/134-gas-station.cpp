class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         int n=gas.size();
        vector<int>arr(2*n);
        for(int i=0;i<n;i++){
            arr[i]=gas[i]-cost[i];
        }
        for(int i=n;i<2*n;i++){
            arr[i]=arr[i-n];
        }
        int s=0,sum=0;
        for(int i=0;i<2*n;i++){
            if(sum+arr[i]>=0 && i-s<=n-1 && s>-1){
                sum+=arr[i];
                if(i-s==n-1)return s;
            }else{
                s=-1;
                sum=0;
            }
            
            if(s==-1 && arr[i]>=0){
                s=i;
                sum+=arr[i];
            }
        }
        return -1;
    }
};