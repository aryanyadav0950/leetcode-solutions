class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    int gcdOfOddEvenSums(int n) {
        vector<int> even;
        vector<int> odd;
        int i = 1;
        
        // Keep looping until both vectors have 'n' elements
        while (even.size() < n || odd.size() < n) {
            if (i % 2 == 0) {
                if (even.size() < n) even.push_back(i);
            } else {
                if (odd.size() < n) odd.push_back(i);
            }
            i++;
        }
        
        int sume = 0, sumo = 0;
        for (int j = 0; j < n; j++) {
            sume += even[j];
            sumo += odd[j];
        }
        
        return gcd(sume, sumo);
    }
};