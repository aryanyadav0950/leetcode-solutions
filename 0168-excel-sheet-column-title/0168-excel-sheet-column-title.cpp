class Solution {
public:

    string convertToTitle(int columnNumber) {
        int c=columnNumber;
        string ans="";
        while(c>0){
            c--;
            int rem=c%26;
            ans+=('A'+rem);
            c=c/26;

        }
    reverse(ans.begin(),ans.end());
    return ans;

        
    }
};