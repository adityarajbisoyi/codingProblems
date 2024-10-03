Solution 1-:
Code-:
bool helper(vector<int>arr, int sum,int n)
{
        if(n==0)
        {
            if(sum==0) return 1;
            else return 0;
        }
        
        if(sum>=arr[n-1])
        return helper(arr,sum-arr[n-1],n-1) || helper(arr,sum,n-1);
        else
        return helper(arr,sum,n-1);
}

bool isSubsetSum(vector<int>arr, int sum)
{
        int n=arr.size();
        return helper(arr,sum,n);
}



Solution 2-:
Code-:
bool helper(int memo[101][10001],vector<int>arr, int sum,int n)
{
        if(n==0)
        {
            if(sum==0)
            return 1;
            else
            return 0;
        }
        
        if(memo[n][sum]!=-1) return memo[n][sum];
        
        int res;
        if(sum>=arr[n-1])
        res= helper(memo,arr,sum-arr[n-1],n-1) || helper(memo,arr,sum,n-1);
        else
        res= helper(memo,arr,sum,n-1);
        return memo[n][sum]=res;
}

bool isSubsetSum(vector<int>arr, int sum)
{
        int n=arr.size();
        int memo[101][10001];
        memset(memo,-1,sizeof(memo));
        return helper(memo,arr,sum,n);
}


Python Code-:
class Solution:
    def helper(self, memo, arr, sum, n):
        if n == 0:
            # If no items are left, return True only if sum is 0
            return sum == 0
        
        # If the subproblem has already been solved, return the cached result
        if memo[n][sum] != -1:
            return memo[n][sum]

        if sum >= arr[n-1]:
            # Either include the current item or don't include it
            res = self.helper(memo, arr, sum - arr[n-1], n-1) or self.helper(memo, arr, sum, n-1)
        else:
            # Exclude the current item
            res = self.helper(memo, arr, sum, n-1)

        # Cache the result
        memo[n][sum] = res
        return res

    def isSubsetSum(self, N, arr, sum):
        # Initialize the memoization table with -1
        memo = [[-1 for _ in range(sum + 1)] for _ in range(N + 1)]
        
        # Call the helper function with initialized memo table
        return self.helper(memo, arr, sum, N)