//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int partition(int arr[],int n){
        int pind = 0;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                swap(arr[i],arr[pind]);
                pind++;
            }
        }
        return pind;
    }
    
    int missingNumber(int arr[], int n) 
    { 
       int k = partition(arr,n);
       
       for(int i=0;i<k;i++){
           int val = abs(arr[i]);
           if(val-1<k && arr[val-1]>0){
               arr[val-1] = -arr[val-1];
           }
       }
       
       for(int i=0;i<k;i++){
           if(arr[i]>0){
               return i+1;
           }
       }
       
       return k+1;
       
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends
