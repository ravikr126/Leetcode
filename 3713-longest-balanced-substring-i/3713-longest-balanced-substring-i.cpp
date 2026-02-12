int freq[26]={0};
class Solution {
public:
    static int longestBalanced(string& s) {
        int cnt=1, n=s.size();
        for(int l=0; l<n; l++){
            memset(freq, 0, sizeof(freq));
            int uniq=0, maxF=0, cntMax=0;
            for(int r=l; r<n; r++){
                int f=++freq[s[r]-'a'];
                uniq+=(f==1);
                const bool gr=f>maxF, eq=f==maxF, less=!(gr|eq);
                maxF=(-gr & f)+(-!gr &maxF);
                cntMax=(-gr & 1)+(-eq & (cntMax+1))+(-less & cntMax);
                const bool need=(uniq==cntMax & cnt<r-l+1);
                cnt=(-need & (r-l+1))+( -!need & cnt);
            }
        }
        return cnt;
    }
};