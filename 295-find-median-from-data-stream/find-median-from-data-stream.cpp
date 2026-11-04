class MedianFinder {
public:
    multiset<int> s1;
    multiset<int> s2;
    int size = 0;
    MedianFinder() {
        size = 0;
    }

    void addNum(int num) {
        size++;
        int n = (size / 2);
        if (s1.empty() && s2.empty()) {
            s1.insert(num);
        }
        // else if (s2.empty()) {
        //     s2.insert(num);
        // }
        if (size == 1)
        return;
        
        if (*(prev(s1.end())) < num) {
            s2.insert(num);
        }
        else {
            s1.insert(num);
        }
        while (s1.size() > n) {
                auto it = prev(s1.end());
                s2.insert(*it);
                s1.erase(it);
            }
            
            while (s1.size() < n) {
                auto it = s2.begin();
                s1.insert(*it);
                s2.erase(it);
            }
        // cout<<"answer"<<endl;
        // for (auto i:s1)
        // cout<<i<<" ";
        // cout<<endl;
        
        // for (auto i:s2)
        // cout<<i<<" ";
        // cout<<endl;
    }
    
    double findMedian() {
        if (size == 1)
        return *(s1.begin());
        
        int a = *(prev(s1.end()));
        int b = *(s2.begin());
        double ans;
        if (size % 2 != 0)
        ans =  static_cast<double>(b);
        else
        ans = (static_cast<double>(a) + static_cast<double>(b)) / 2;
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */