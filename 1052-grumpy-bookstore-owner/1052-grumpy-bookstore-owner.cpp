class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        vector<int>& arr = customers;
        int n = arr.size();
        int k = minutes;
        int prevloss = 0;
        
        for (int i = 0; i < k; i++) {
            if (grumpy[i] == 1) prevloss += arr[i];
        }
        
        int currloss = prevloss;
        int maxloss = prevloss;
        int i = 1;
        int j = k;
        int idx = 0;
        
        while (j < n) {
          
            currloss = prevloss;
            if (grumpy[j] == 1) currloss += arr[j];
            if (grumpy[i - 1] == 1) currloss -= arr[i - 1];
            
            if (maxloss < currloss) {
                maxloss = currloss;
                idx = i; 
            }
            prevloss = currloss;
            i++;
            j++;
        }
        
   
        for (int x = idx; x < idx + k; x++) {
            grumpy[x] = 0;
        }
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) sum += arr[i];
        }
        return sum;
    }
};