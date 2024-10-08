class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        int i=0;
        int j = m-1;
        int mini = INT_MAX;
        while(j<a.size()){
            int diff = (a[j]-a[i]);
            i++;
            j++;
            mini = min(mini,diff);
        }
        return mini;
    }   
};
