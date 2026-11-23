class ProductOfNumbers {
private:
    vector<int> prefixProducts;

public:
    ProductOfNumbers() {
        prefixProducts = {1};
    }
    
    void add(int num) {
        if (num == 0) {
            // Reset prefix products when 0 is encountered
            prefixProducts = {1};
        } else {
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = prefixProducts.size();
        // If k is greater than or equal to the current non-zero streak,
        // a 0 was included in the last k elements
        if (k >= n) {
            return 0;
        }
        return prefixProducts.back() / prefixProducts[n - 1 - k];
    }
};