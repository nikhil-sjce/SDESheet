class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>>ans;
        if(nums.size() < 3){
            return ans;
        }
        sort(nums.begin(), nums.end());
        for(int i=0;i<=nums.size()-3;i++){
            if(i==0 || (i > 0 && nums[i-1] != nums[i])){
                int j = i+1, k = nums.size()-1, sum = 0 - nums[i];
                while(j<k){
                    if(nums[j] + nums[k] == sum){
                        vector<int>v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        ans.push_back(v);
                        while(j<k && nums[j] == nums[j+1])
                            j++;
                        while(j<k && nums[k] == nums[k-1])
                            k--;
                        j++;k--;
                    }
                    else if(nums[j] + nums[k] < sum)
                        j++;
                    else if(nums[j] + nums[k] > sum)
                        k--;
                }
            }
        }
        return ans;
    }
};