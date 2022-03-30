vector<int> Smallestonleft(int arr[], int n){
    vector<int>v;
    set<int>s;
    s.insert(-1);
    for(int i=0;i<n;i++){
        if(i==0){
            v.push_back(-1);
            s.insert(arr[i]);
        }else{
            s.insert(arr[i]);
            auto iterator = s.find(arr[i]);
            iterator--;
            v.push_back(*iterator);
        }
    }
    return v;
}