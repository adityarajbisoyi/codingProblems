1)Fractional knapsack.   -> Greedy 
2)0/1 knapsack           -> 0 means add kro and 1 means add kro (multiple occurence not allowed)
3)unbounded knapsack     -> (multiple occurence of same value allowed)


Solution 1-:
Steps-:
using recursion

Code-:
int helper(int wt[],int val[],int W,int n)
{
        if(W==0 || n==0) return 0;
        if(W>=wt[n-1])
        return max(val[n-1] +helper(wt,val,W-wt[n-1],n-1),helper(wt,val,W,n-1));
        else
        return helper(wt,val,W,n-1);
}

int knapSack(int W, int wt[], int val[], int n) 
{ 
        return helper(wt,val,W,n);
}


Solution 2-:
Using memo

Code-:
int helper(int memo[1001][1001],int wt[],int val[],int W,int n)
{
        if(W==0 || n==0) return 0;
        
        if(memo[n][W]!=-1) return memo[n][W];
        
        int res;
        if(W>=wt[n-1])
        res= max(val[n-1] +helper(memo,wt,val,W-wt[n-1],n-1),
                             helper(memo,wt,val,W,n-1));
        else
        res= helper(memo,wt,val,W,n-1);
        return memo[n][W]=res;
}

int knapSack(int W, int wt[], int val[], int n) 
{ 
        int memo[1001][1001];
        memset(memo,-1,sizeof(memo));
        return helper(memo,wt,val,W,n);
}


Python Code-:
class Solution:
    
    # Helper function for memoization
    def helper(self, memo, wt, val, W, n):
        if W == 0 or n == 0:
            return 0

        # If the value is already computed, return it
        if memo[n][W] != -1:
            return memo[n][W]

        if W >= wt[n-1]:
            # Either include the current item or exclude it
            res = max(val[n-1] + self.helper(memo, wt, val, W - wt[n-1], n-1),
                      self.helper(memo, wt, val, W, n-1))
        else:
            # Exclude the current item
            res = self.helper(memo, wt, val, W, n-1)

        # Cache the result
        memo[n][W] = res
        return res
    
    # Function to return max value that can be put in knapsack of capacity W
    def knapSack(self, W, wt, val):
        # Automatically compute 'n' from the length of the weights array
        n = len(wt)
        
        # Initialize memoization table with -1
        memo = [[-1 for _ in range(W + 1)] for _ in range(n + 1)]
        
        # Call the helper function with initialized memo table
        return self.helper(memo, wt, val, W, n)