class Solution{
    public:
    void frequencyCount(vector<int>& arr,int n, int p){
        for(int  i=0;i<n;i++)
            arr[i] = arr[i] - 1;
        int count = 0;
        for(int i=0;i<n;i++){
            if(arr[i] >= n){
                count++;
                arr[i] = 0;
            }
        }
        for(int i=0;i<n;i++)
            arr[arr[i]%n] = arr[arr[i]%n] + n;
        for(int  i=0;i<n;i++)
            arr[i] = arr[i]/n;
        arr[0] = arr[0] - count;   
    }
};