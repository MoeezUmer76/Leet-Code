#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        for (int i = 0;i < nums.size();i++)
        {
            int sum = 0;
            for (int j = i + 1;j < nums.size();j++)
            {
                sum = nums[i] + nums[j];
                if (sum == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};