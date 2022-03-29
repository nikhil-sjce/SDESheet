class Solution{
    public:
    int maxLen(vector<int>&A, int n){
        unordered_map<int,int>um;
        int i = 0, sum = 0, maxLength = INT_MIN;
        while(i<n){
            sum+=A[i];
            if(um.find(sum) == um.end())
                um[sum] = i+1;
            if(sum == 0)
                maxLength = i+1;
            if(um.find(sum) != um.end()){
                if(maxLength < (i + 1 - um[sum]) )
                    maxLength = i + 1 - um[sum];
            }
            i++;
        }
        return maxLength;
    }
};