class element{
    public:
    int index=0,steps=0;
    element(int in,int st){
        index=in;
        steps=st;
    }
};

class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,queue<int>> ump;
        int n=arr.size();
        
        bool seen[n];
        for(int i=0;i<n;++i){
            ump[arr[i]].push(i);
            seen[i]=0;
        }
        
        queue<element> q;
        q.push(element(0,0));
        
        while(!q.empty()){
            
            element t=q.front();
            q.pop();
            
            if(t.index==n-1)
                return t.steps;

            if(t.index+1<=n and seen[t.index+1]==0){
                q.push(element(t.index+1,t.steps+1));
                seen[t.index+1]=1;
            }
            if(t.index-1>=0 and seen[t.index-1]==0){
                q.push(element(t.index-1,t.steps+1));
                seen[t.index-1]=1;
            }
            queue<int> &it=ump[arr[t.index]];
            while(!it.empty()){
                int next_occ=it.front();
                it.pop();
                
                if(seen[next_occ]==0){
                    q.push(element(next_occ,t.steps+1));
                    seen[next_occ]=1;
                }
            }
            
        }
        
        return -1;
    }
};