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
// Method 3 :
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;
        // step 1 : find the break point
        for(k = n-2;k>=0;k--){
            if(nums[k] < nums[k+1]){
                break;
            }
        }
        if(k < 0){
            // if no break point then just reverse
            reverse(nums.begin(), nums.end());
        }else{
            for(l=n-1;l>=0;l--){
                // step 2 find 1st element from last greater then break point
                if(nums[l] > nums[k]){
                    break;
                }
            }
            // swap 3 element at index l and k
            swap(nums[l], nums[k]);
            // step 4 reverse from index k + 1
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};
