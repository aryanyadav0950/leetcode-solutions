class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        unordered_map<int,int> m;
        
        for(int ele:digits)
            m[ele]++;
        
        for(int i=100;i<1000;i+=2){
            int x=i;
            int a=x%10;
            x=x/10;
            int b=x%10;
            x=x/10;
            int c=x%10;
            
            if(m.find(a)!=m.end() && m[a]>0){
                m[a]--;
                
                if(m.find(b)!=m.end() && m[b]>0){
                    m[b]--;
                    
                    if(m.find(c)!=m.end() && m[c]>0)
                        ans.push_back(i);
                    
                    m[b]++;
                }
                
                m[a]++;
            }
        }
        
        return ans;
    }
};