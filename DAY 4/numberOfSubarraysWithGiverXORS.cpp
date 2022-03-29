int Solution::solve(vector<int> &a, int b) {
    map<int,int>mp;
    int xori = 0, n = a.size();
    long long int ans = 0;
    for(int i=0;i<n;i++){
        xori = xori^a[i];
        if(xori == b)
            ans++;
        if( mp.find(xori^b) != mp.end())
            ans = ans + mp[xori^b];
        mp[xori]++;
    }
    return ans;
}