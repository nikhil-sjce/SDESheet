class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>nums1, v;
        nums1 = nums;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size()-1, n1, n2;
        while(i<nums.size() && j>=0 && j>i){
            if(nums[i] + nums[j] == target){
                n1 = nums[i];
                n2 = nums[j];
                break;
            }
            else if(nums[i] + nums[j] < target)
                i++;
            else
                j--;
        }
        for(int i=0;i<nums1.size();i++){
            if(nums1[i] == n1)
                v.push_back(i);
            else if(nums1[i] == n2)
                v.push_back(i);
        }
        return v;
    }
};