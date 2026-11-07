class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> avaiable;
        priority_queue<
            pair<pair<long long int,int>,int>,
            vector<pair<pair<long long int,int>,int>>,
            greater<pair<pair<long long int,int>,int>>
        > not_avaiable;
        for (int i = 0; i < servers.size(); i++) {
            avaiable.push({servers[i], i});
        }
        // cout<<avaiable.empty()<<endl;
        long long int a = 0, n = tasks.size(), t = -1, curr1, curr2, curr3, temp = 0; 
        vector<int> ans(n);
        while (a < n) {
            if (avaiable.size() == 0) {
                t = not_avaiable.top().first.first;
            }
            else
            t++;
            while (!not_avaiable.empty()) {
                // cout<<"cahran"<<endl;
                curr1 = not_avaiable.top().first.first;
                curr2 = not_avaiable.top().first.second;
                curr3 = not_avaiable.top().second;
                if (curr1 > t)
                break;
                not_avaiable.pop();
                avaiable.push({curr2, curr3});
            }
            // cout<<t<<" "<<avaiable.size()<<endl;
            while (!avaiable.empty() && t >= a && a < n) {
                curr1 = avaiable.top().first;
                curr2 = avaiable.top().second;
                avaiable.pop();
                ans[a] = curr2;
                // cout << "After pop: " << avaiable.size() << endl;
                not_avaiable.push({{t + tasks[a], curr1}, curr2});
                a++;
            }
            // cout<<endl;
            temp++;
        }
        return ans;
    }
};