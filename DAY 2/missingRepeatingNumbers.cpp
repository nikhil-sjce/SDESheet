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
