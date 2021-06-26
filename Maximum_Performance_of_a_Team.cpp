class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<pair<int,int>> eff_sp;
        for (int i=0; i<n; i++)
            eff_sp.push_back({efficiency[i], speed[i]});
        
        sort(eff_sp.rbegin(), eff_sp.rend());
        
        //min heap using priority queue
        priority_queue<int, vector<int>, greater<int>> speed_heap;
        long int perf=0, speed_sum=0;
        int mod = 1000000007;
        
        for (auto ele: eff_sp){
            if (speed_heap.size()>k-1){
                speed_sum -= speed_heap.top();
                speed_heap.pop();
            }
            speed_heap.push(ele.second);
            
            speed_sum += ele.second;
            perf = max(perf, speed_sum*ele.first);
        }
        return perf%mod;
    }
};