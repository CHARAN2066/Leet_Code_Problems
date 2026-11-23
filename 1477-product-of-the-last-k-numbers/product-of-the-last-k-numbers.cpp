class ProductOfNumbers {
public:
    vector<int> nums;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int pr=1,n=nums.size();
        for(int i=0;i<k;i++)
        {
            if((n-1-i)<0)
            return pr;
            pr*=nums[n-1-i];
        }
        return pr;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */