constexpr int N=1e5+1;
int Rt[N], Rk[N]; 
int freq[N];
class UnionFind {
public:
    UnionFind(int n){
        iota(Rt, Rt+n, 0);
        fill(Rk, Rk+n, 0);
    }
    int Find(int x) {
        // compress path
        return (x == Rt[x])?x:Rt[x]=Find(Rt[x]);
    }
    bool Union(int x, int y) {
        x=Find(x), y=Find(y);
        if (x==y) return 0;
        if (Rk[x]>Rk[y]) swap(x, y);
        Rt[x]=y;
        if (Rk[x]==Rk[y]) Rk[y]++;
        return 1;
    }
};

class Solution {
public:
    static int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        const int n=source.size();
        UnionFind G(n);
        
        for(auto& sw : allowedSwaps)
            G.Union(sw[0], sw[1]);

        // Group indices in the same component
        vector<vector<int>> components(n);
        for(int i=0; i<n; i++)
            components[G.Find(i)].push_back(i);

        int match=0;
        
        // Process each component
        for(int i=0;i<n; i++) {
            if (components[i].empty()) continue;

            // Count freq of source
            for(int idx : components[i])
                freq[source[idx]]++;

            // Check how many target values in this component
            for(int idx : components[i]) {
                if (freq[target[idx]]>0) {
                    freq[target[idx]]--;
                    match++;
                }
            }

            // reset freq for the next component
            for(int idx : components[i]) 
                freq[source[idx]]=0; 
        }
        return n-match;
    }
};