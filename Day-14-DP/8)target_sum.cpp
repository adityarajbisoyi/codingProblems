int mod=1e9+7;
	long long int helper(int memo[101][10001],vector<int>arr,int sum,int n)
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
    
	long long int perfectSum(vector<int>arr, int n, int sum)
	{
        int memo[101][10001];
        memset(memo,-1,sizeof(memo));
        return helper(memo,arr,sum,n);
	}
    long long findTargetSumWays(int n, vector<int>& A, int target) {
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=A[i];
        }
        int diff=(sum+target)/2;
        if((sum+target)%2!=0) return 0;
        else
        return perfectSum(A,n,diff);
    }


Python Code-:
class Solution:
    def findTargetSumWays(self, n, arr, target):
        total_sum = sum(arr)
        
        # If target + total_sum is odd or target is greater than total_sum, there's no valid way
        if (target + total_sum) % 2 != 0 or target > total_sum or target < -total_sum:
            return 0
        
        S1 = (target + total_sum) // 2
        
        # Call the function to count subsets with sum S1
        return self.countSubsetsWithSum(arr, n, S1)

    def countSubsetsWithSum(self, arr, n, sum):
        # Create a DP array to store the count of subsets
        dp = [[0 for _ in range(sum + 1)] for _ in range(n + 1)]
        
        # There is one way to get a sum of 0 (by choosing no elements)
        for i in range(n + 1):
            dp[i][0] = 1
        
        # Fill the DP table
        for i in range(1, n + 1):
            for j in range(0, sum + 1):
                # Exclude the current element
                dp[i][j] = dp[i - 1][j]
                
                # Include the current element if it does not exceed the sum
                if arr[i - 1] <= j:
                    dp[i][j] += dp[i - 1][j - arr[i - 1]]
        
        return dp[n][sum]