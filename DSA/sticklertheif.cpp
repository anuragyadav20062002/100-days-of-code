//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int incl_curr = arr[0]; 
        int excl_curr = 0; 
        
        //storing sum up to previous element including and 
        //excluding it in respective variables.
        int incl_prev = incl_curr; 
        int excl_prev = excl_curr; 
        
        for (int i = 1; i < n; i++)
        {
            //updating sum up to current element excluding it as maximum
            //of sum upto previous element excluding and including it.
            excl_curr = max(incl_prev, excl_prev); 
            
            //updating sum up to current element including it as sum up to 
            //previous element excluding it + current element.
            incl_curr = excl_prev + arr[i]; 
            
            //updating sum upto previous element including and 
            //excluding it for next iteration.
            excl_prev = excl_curr;  
            incl_prev = incl_curr; 
        }
        
        //returning the maximum of sum up to current element  
        //including and excluding it.
        return max(excl_curr, incl_curr);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends