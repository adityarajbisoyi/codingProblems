Solution 1-:
int perfectSum(int arr[], int n, int sum)
{
        if(n==0)
        {
            if(sum==0)
            return 1;
            else
            return 0;
        }
        else if(sum>=arr[n-1])
        return perfectSum(arr,n-1,sum-arr[n-1]) + perfectSum(arr,n-1,sum);
        else
        return perfectSum(arr,n-1,sum);
}

Solution 2-:

Code-:
int mod=1e9+7;
int helper(int memo[1001][1001],int arr[], int sum,int n)
{
        if(n==0)
        {
            if(sum==0) return 1;
            else
            return 0;
        }
        
        if(memo[n][sum]!=-1) return memo[n][sum];
        
        int res;
        if(sum>=arr[n-1])
        res= helper(memo,arr,sum-arr[n-1],n-1)%mod + helper(memo,arr,sum,n-1)%mod;
        else
        res= helper(memo,arr,sum,n-1)%mod;
        return memo[n][sum]=res%mod;
}

int perfectSum(int arr[], int n, int sum)
{
        int memo[1001][1001];
        memset(memo,-1,sizeof(memo));
        return helper(memo,arr,sum,n);
}


Python Code-:
class Solution:
    def helper(self, memo, arr, target_sum, n):
        if n == 0:
            # If no items left, check if the sum is 0
            return 1 if target_sum == 0 else 0
        
        # If the result for the subproblem is already computed, return it
        if memo[n][target_sum] != -1:
            return memo[n][target_sum]

        mod = 10**9 + 7
        res = 0
        
        # Include the current item if it doesn't exceed the target sum
        if target_sum >= arr[n-1]:
            res += self.helper(memo, arr, target_sum - arr[n-1], n-1) % mod
        
        # Exclude the current item
        res += self.helper(memo, arr, target_sum, n-1) % mod
        
        # Cache the result and apply the modulo
        memo[n][target_sum] = res % mod
        return memo[n][target_sum]

    def perfectSum(self, arr, n, target_sum):
        # Initialize the memoization table with -1
        memo = [[-1 for _ in range(target_sum + 1)] for _ in range(n + 1)]
        
        # Call the helper function with initialized memo table
        return self.helper(memo, arr, target_sum, n)