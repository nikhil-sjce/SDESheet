// Method : 1 (IMP)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        for(;i>0;i--){
            if(nums[i-1]>=nums[i] && i-1>=0)
                continue;
            else 
                break;
        }
        if(i==0)
            sort(nums.begin(), nums.end());
        else{
            int k = i-1;
            int minDiff = INT_MAX, minIndex;
            for( ;i<nums.size();i++){
                int diff = nums[i] - nums[k];
                if(diff != 0 && diff < minDiff && diff > 0){
                    minDiff = min(minDiff, diff);
                    minIndex = i;
                }  
            }
            swap(nums[k], nums[minIndex]);
            sort(nums.begin() + k + 1, nums.begin() + nums.size() - 1 + 1);
        }
    }
};
// Method 2 : 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(next_permutation(nums.begin(),nums.end()))
           return ;
        else
            sort(nums.begin(),nums.end());
    }
};