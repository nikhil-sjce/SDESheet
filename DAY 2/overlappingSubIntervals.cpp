class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=0;i<intervals.size();i++){
            if(end < intervals[i][0]){
                temp.push_back(start);
                temp.push_back(end);
                start = intervals[i][0];
                end = intervals[i][1];
                ans.push_back(temp);
                temp.clear();
            }else{
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
        }
        temp.push_back(start);
        temp.push_back(end);
        ans.push_back(temp);
        return ans;
    }
};
