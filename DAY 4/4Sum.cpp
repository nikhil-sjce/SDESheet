class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size(); 
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        if (nums.empty())
            return ans;
        for(int i=0;i<=n-4;i++){
            for(int j =i+1 ;j<=n-3;j++){
                int sum = target - nums[j] - nums[i];
                int k = j+1, l = n-1;
                while(k<l){
                    int twoSum = nums[k] + nums[l];
                    if(twoSum < sum)
                        k++;
                    else if(twoSum > sum)
                        l--;
                    else{
                        vector<int>quad;
                        quad.push_back(nums[i]);
                        quad.push_back(nums[j]);
                        quad.push_back(nums[k]);
                        quad.push_back(nums[l]);
                        ans.push_back(quad);
                        while(k<l && nums[k] == quad[2])
                            k++;
                        while(k<l && nums[l] == quad[3])
                            l--;
                    }
                }
                while( j+1 < n && nums[j+1] == nums[j])
                    j++;
            }
            while(i+1 < n && nums[i+1] == nums[i])
                i++;
        }
        return ans;
    }
};