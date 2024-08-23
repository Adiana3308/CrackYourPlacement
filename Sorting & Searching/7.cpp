#include <bits/stdc++.h> 

/* Partition will be done according to the days.Like how many chapters
   to complete in a day.
*/
bool isPossible(vector<int>&time,int n,int m,long long int mid)
{
    int chapterCount = 1;
    long long int timeSum=0;
    
    for(int i=0;i<m;i++)
    {
        if(timeSum+time[i]<=mid)
        {
            timeSum+=time[i];
        }
        else
        {
            chapterCount++;
            if(chapterCount>n || time[i]>mid)
            {
                return false;
            }
            timeSum=time[i];
        }
    }
    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int>&time) 
{	
	long long int s=0;
    long long int sum=0;

    for(int i=0;i<m;i++)
    {
        sum+=time[i];
    }

    long long int e = sum;
    long long int mid = s + (e-s)/2;
    long long int ans=-1;
    while(s<=e)
    {
        if(isPossible(time,n,m,mid))
        {
            ans=mid;
            e=mid-1;  
        }
        else
        {
            s=mid+1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
