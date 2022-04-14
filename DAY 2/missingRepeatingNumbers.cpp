pair<int,int> missingAndRepeating(vector<int> &arr, int n){
	long long int sum=0, sum0=0, sumSquare=0, sumSquare0=0;
    for(int i=0;i<n;i++){
        sum0+=(long long int)arr[i];
        sumSquare0+=(long long int)arr[i]*(long long int)arr[i];
    }
    sum = ((long long int)((long long int)n*((long long int)n+1))/2);
    sumSquare = ((long long int)((long long int)n*((long long int)n+1)*(2*(long long int)n+1))/6);
    long long int diff = (long long int)sum - (long long int)sum0;
    long long int add = ((long long int)((long long int)sumSquare - (long long int)sumSquare0)/(long long int)diff);
    long long int missing = ((long long int)((long long int)diff + (long long int)add)/2);
    long long int repeating = (long long int)((long long int)missing - (long long int)diff);
    return {(long long int)missing, (long long int)repeating};
}

// METHOD 2 USING XOR BITWISE

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
         int res=0;
         for(int i=0;i<n;i++){
             res=res^arr[i]^(i+1);
         }
         int x=res&~(res-1);
         int res1=0,res2=0;
         for(int i=0;i<n;i++){
            
             if((x&arr[i])==0){
                 res1=res1^arr[i];
             }
             else{
                 res2=res2^arr[i];
             }
             if((x&(i+1))==0){
                 res1=res1^(i+1);
             }
             else{
                 res2=res2^(i+1);
             }
         }
         int *a=new int[2];
         for(int i=0;i<n;i++){
             if(arr[i]==res1){
                 int t=res2;
                 res2=arr[i];
                 res1=t;
                 break;
             }
         }
         a[0]=res2;
         a[1]=res1;
         return a;
    }
};