class Solution {
public:
    int maxProfit(vector<int>& prices){
        int ans = INT_MIN, currMax = prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            int diff = currMax - prices[i];
            if(diff > ans && diff>=0)
                ans = diff;
            if(prices[i] > currMax)
                currMax = prices[i];
        }
        if(ans == INT_MIN)
            return 0;
        else
            return ans;
    }
};