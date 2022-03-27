class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        int i = 0, j = nums.size()-1;
        while(i<nums.size() && j>=0 && j>i){
            if(nums[i] + nums[j] == target){
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
            else if(nums[i] + nums[j] < target)
                i++;
            else
                j--;
        }
        return v;
    }
};