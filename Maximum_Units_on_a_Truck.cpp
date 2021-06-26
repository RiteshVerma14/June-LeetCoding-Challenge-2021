#include<bits/stdc++.h>
using namespace std;

class Solution 
{
	public:
	    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
		{
	        vector<pair<int,int>> vec;
	        int res=0;
	        for(int i=0; i<boxTypes.size(); i++)
	            vec.push_back(make_pair(boxTypes[i][0],boxTypes[i][1]));
	        sort(vec.begin(), vec.end(), [](const pair<int,int> &a , const pair<int,int> &b) { return a.second > b.second ; });
	        for(int i=0; i<vec.size(); i++)
	        {
	            if(vec[i].first <= truckSize)
	            {
	                res = res + (vec[i].first*vec[i].second);
	                truckSize = truckSize - vec[i].first;
	            }
	            else
	            {
	                res = res + (truckSize*vec[i].second);
	                break;
	            }
	        }
	        return res;
	    }
};

int main()
{
	Solution sol;
	vector<vector<int>> box = {{5,10},{2,5},{4,7},{3,9}};         
	int target = 10;
	cout<<"Result is : "<<sol.maximumUnits(box,target);
}
