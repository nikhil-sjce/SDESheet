// Without DP

class Solution {
public:
    vector<vector<int>> generate(int num) {
        vector<vector<int>>ans;
        if(num==1){
            vector<int>v;
            v.push_back(1);
            ans.push_back(v);
            return ans;
        }
        else if(num==2){
            vector<int>v1,v2;
            v1.push_back(1);
            v2.push_back(1);
            v2.push_back(1);
            ans.push_back(v1);
            ans.push_back(v2);
            return ans;
        }
        else{
            vector<int>v1,v2;
            v1.push_back(1);
            v2.push_back(1);
            v2.push_back(1);
            ans.push_back(v1);
            ans.push_back(v2);
            for(int i=3;i<=num;i++){
                vector<int>v;
                int ceilVal = (i / 2) + ((i % 2) != 0);
                for(int j=0;j<ceilVal;j++){
                    if(j==0){
                        v.push_back(1);
                    }
                    else{
                        v.push_back(ans[i-2][j-1] + ans[i-2][j]);
                    }
                }
                if(i%2==0){
                    int size1 = v.size();
                    while(size1--){
                        v.push_back(v[size1]);
                    }
                }
                else{
                    int size1 = v.size()-1;
                    while(size1--){
                        v.push_back(v[size1]);
                    }
                }
                ans.push_back(v);
            }
            return ans;
        }
    }
};