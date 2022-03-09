class Solution{
  public:
  
    long long int merge(long long arr[], long long int l, long long int mid, long long int r, long long int n){
        long long int i = l, j = mid+1, x = l; 
        long long count = 0;
        long long int b[n];
        while(i<=mid && j<=r){
            if(arr[i] <= arr[j]){
                b[x++] = arr[i++];
            }else{
                b[x++] = arr[j++];
                count = count + mid - i + 1  ;
            }
        }
        while(i<=mid){
            b[x++] = arr[i++];
        }
        while(j<=r){
            b[x++] = arr[j++];
        }
        for(x = l ; x<=r ; x++){
            arr[x] = b[x];
        }
        return count;
        
    }

    long long int mergeSort(long long arr[], long long int l, int r, long long int n){
        long long int count = 0;
        if(r>l){
            long long int mid = (l+r)/2;
            count += mergeSort(arr, l, mid, n);
            count += mergeSort(arr, mid+1, r, n);
            count += merge(arr, l, mid, r, n);
        }
        return count;
    }
    
    long long int inversionCount(long long arr[], long long n){
        long long int count;
        count = mergeSort(arr, 0, n-1, n);
        return count;
    }

};