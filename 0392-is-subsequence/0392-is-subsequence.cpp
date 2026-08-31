class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.size();
        int n=t.size();
        int count=0;
        int idx=-1;
        for(int i=0;i<m;i++){
            for(int j=idx+1;j<n;j++){
                if(s[i]==t[j]){
                    idx=j;
                    count++;
                    break;
                }
            }
        
        }
        if(count==m) return true;
        else return false;
        
        
    }
};