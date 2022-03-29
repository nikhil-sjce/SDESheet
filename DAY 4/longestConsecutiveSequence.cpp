class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        int count = 0, ans = INT_MIN, ele;
        for(auto x : mp){
            if(count == 0){
                ele = x.first;
                count++;
            }
            else if(ele + 1 == x.first){
                count++;
                ele = x.first;
            }
            else if(ele + 1 != x.first){
                ans = max(ans, count);
                ele = x.first;
                count = 1;
            }
        }
        ans = max(ans, count);
        return ans;
    }
};