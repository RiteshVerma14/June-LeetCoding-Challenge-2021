class Solution {
public:
        vector<vector<int>> generate(int line) {
            vector<vector<int>> result;
            result.push_back({1});
            for(int i = 2; i<=line; i++) 
            {
                vector<int> curr(i);
                vector<int> prev = result[i-2];
                curr[0] = 1;
                for(int j = 0; j<prev.size()-1; j++) 
                    curr[j+1] = prev[j] + prev[j+1];
                curr[i-1] = 1;
                result.push_back(curr);
            }
            return result;
    }
};
