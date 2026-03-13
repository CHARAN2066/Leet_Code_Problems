class Solution {
public:
      struct Compare {
        bool operator()(const std::tuple<long long int, long long int, long long int>& a, 
                        const std::tuple<long long int, long long int, long long int>& b) {
            if (std::get<0>(a) == std::get<0>(b)) {
                return std::get<1>(a) > std::get<1>(b); 
            }
            return std::get<0>(a) > std::get<0>(b);
        }
    };
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) 
    {
        long long int n=workerTimes.size();
        priority_queue<std::tuple<long long int, long long int, long long int>, std::vector<std::tuple<long long int, long long int, long long int>>, Compare> pq;
        for(long long int i=0;i<workerTimes.size();i++)
        {
            pq.push({workerTimes[i],workerTimes[i],i});
        }
        vector<long long int> number(n,1);
        long long int m=0;
        while(mountainHeight>0)
        {
            auto element=pq.top();
            long long int first=get<0>(element);
            m=max(m,first);
            long long int second=get<1>(element);
            long long int third=get<2>(element);
            pq.pop();
            number[third]++;
            pq.push({first+second*number[third],second,third});
            mountainHeight--;
            // cout << "Extracted: (" << std::get<0>(element) << ", " << std::get<1>(element) << ", " << std::get<2>(element) << ")\n";
        }
        return m;        
    }
};