class solution{
    int merge(vector<int> &arr, int left, int mid, int right, int n){
        int i = left, j = mid+1, k = left, b[n], count = 0;
        
        while(i<=mid and j<=right)
            {
                if(arr[i]>2*1ll*arr[j])
                {
                    count+=(mid-i+1);
                    j++;
                }
                else
                {
                    i++;
                }
            }
        i = left; j = mid+1;
        while(i<=mid && j<=right){
            if(arr[i] <= arr[j])
                b[k++] = arr[i++];
            else{
                b[k++] = arr[j++];
            }
        }
        while(i<=mid)
            b[k++] = arr[i++];
        while(j<=right)
            b[k++] = arr[j++];
        for(k = left ; k<=right ; k++)
            arr[k] = b[k];
        return count;
    }

    int mergeSort(vector<int> &arr, int left, int right, int n){
        int count = 0;
        if(right > left){
            int mid = (left + right)/2;
            count+=mergeSort(arr, left, mid, n);
            count+=mergeSort(arr, mid+1, right, n);
            count+=merge(arr, left, mid, right, n);
        }
        return count;
    }

    int reversePairs(vector<int> &arr, int n){
        return mergeSort(arr, 0, n-1, n);
    }
};