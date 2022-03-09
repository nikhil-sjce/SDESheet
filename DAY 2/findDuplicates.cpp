// METHOD : 1 o(n) space
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        int um[n+1] = {0};
        vector<int>v;
        for(int i=0;i<n;i++){
            um[arr[i]]++;
        }
        for(int i=0;i<n+1;i++){
            if(um[i] > 1)
                v.push_back(i);
        }
        if(v.empty()){
            v.push_back(-1);
            return v;
        }
        else{
            return v;
        }
    }
};

// METHOD 2 : In case of one duplicate
class Solution{
  public:
    int duplicates(int arr[], int n) {
        int slow = arr[0], fast = arr[0];
        do{
            slow = arr[slow];
            fast = arr[arr[fast]];
        }while(slow!=fast);
        fast = arr[0];
        while(slow!=fast){
            slow = arr[fast];
            fast = arr[fast];
        }
        return slow;
    }
};

// METHOD 3 : More than one duplicates
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int>v;
        for(int i=0;i<n;i++){
            int index = arr[i]%n;
            arr[index] += n;
        }
        for(int i=0;i<n;i++){
            if( arr[i]/n >= 2 )
                v.push_back(i);
        }
        if(v.size() == 0){
            v.push_back(-1);
            return v;
        }else{
            return v;
        }
    }
};
