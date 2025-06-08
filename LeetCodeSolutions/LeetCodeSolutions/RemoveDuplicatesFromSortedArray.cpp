#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int key;
        int j = 0;
        int k = 0;
        if (nums.size() != 0)
        {
            key = nums[j];
            j++;
            k++;
        }

        for (int i = 1;i < nums.size();i++)
        {
            if (nums[i] != key)
            {
                key = nums[i];
                nums[j] = key;
                j++;
                k++;
            }
        }
        return k;
    }
};