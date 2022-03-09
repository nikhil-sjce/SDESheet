// METHOD 1 :
class Solution{
    public:
        //Function to merge the arrays.
        void sortedInsert(long long arr[], long long m){
            int i = 1;
            int k = arr[0];
            while(i<m && arr[i] < k){
                arr[i-1] = arr[i];
                i++;
            }
            arr[i-1] = k;
        }
        void merge(long long arr1[], long long arr2[], int n, int m) { 
            int i = 0, j = 0;
            while(i<n && j<m){
                if(arr1[i] < arr2[j])
                    i++;
                else{
                    swap(arr1[i], arr2[j]);
                    sortedInsert(arr2, m);
                    i++;
                }
            }
        } 
};

// METHOD 2 : OPtimized
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) { 
            int i = n-1, j = 0;
            while(i>=0 && j<m){
                if(arr1[i] > arr2[j]){
                    swap(arr1[i], arr2[j]);
                    i-- ; j++;
                }
                else
                    break;
            }
            sort(arr1, arr1+n);
            sort(arr2, arr2+m);
        } 
};