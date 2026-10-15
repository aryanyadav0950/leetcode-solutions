class Solution {
public:
    string truncateSentence(string s, int k) {
        int i = 0;
        int count = 0;
        string ans="";
        string anss="";
        for(int i=0;i<s.size();i++){
            if(count==k){
                anss=ans;
                break;
            }
            
            if(s[i]==' ') count++;
            if(count<k) ans+=s[i];
        }
        return ans;
    }
};