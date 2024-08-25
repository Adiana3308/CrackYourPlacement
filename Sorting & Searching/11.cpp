//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
int minSwaps(vector<int>& nums) {
    int n = nums.size();
    
    // Pair the elements with their indices
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = {nums[i], i};
    }
    
    // Sort the array by the first element (values of nums)
    sort(arr.begin(), arr.end());

    // To track visited elements
    vector<bool> visited(n, false);
    int swaps = 0;

    // Traverse the sorted array to count cycles
    for (int i = 0; i < n; i++) {
        // If already visited or in the correct position, skip
        if (visited[i] || arr[i].second == i) {
            continue;
        }

        // Find the cycle length
        int cycle_size = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = arr[j].second;
            cycle_size++;
        }

        // If there is a cycle of size k, we need (k-1) swaps
        if (cycle_size > 1) {
            swaps += (cycle_size - 1);
        }
    }
    
    return swaps;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
