Solution 
Steps-:
1)if sum is odd we cannot split into two equal half
2)if sum is even may be pass (sum/2) to subset sum problem code.

Code-:
bool helper(int memo[101][10001],int arr[], int sum,int n)
{
        if(sum==0) return 1;
        if(n==0) return 0;
        
        if(memo[n][sum]!=-1) return memo[n][sum];
        
        int res;
        if(sum>=arr[n-1])
        res= helper(memo,arr,sum-arr[n-1],n-1) || helper(memo,arr,sum,n-1);
        else
        res= helper(memo,arr,sum,n-1);
        return memo[n][sum]=res;
}

bool isSubsetSum(int arr[], int sum,int n)
{
        int memo[101][10001];
        memset(memo,-1,sizeof(memo));
        return helper(memo,arr,sum,n);
}

int equalPartition(int N, int arr[])
{
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        
        if(sum%2!=0) return 0;
        else
        return isSubsetSum(arr,sum/2,N);
}

Python Code-:
class Solution:
    def helper(self, memo, arr, target_sum, n):
        if target_sum == 0:
            return True  # Found a subset with the required sum
        if n == 0:
            return False  # No items left to consider
        
        # If the result for the subproblem is already computed, return it
        if memo[n][target_sum] != -1:
            return memo[n][target_sum]

        if target_sum >= arr[n-1]:
            # Either include the current item or exclude it
            res = self.helper(memo, arr, target_sum - arr[n-1], n-1) or self.helper(memo, arr, target_sum, n-1)
        else:
            # Exclude the current item
            res = self.helper(memo, arr, target_sum, n-1)

        # Cache the result
        memo[n][target_sum] = res
        return res

    def isSubsetSum(self, arr, target_sum, n):
        # Initialize the memoization table with -1
        memo = [[-1 for _ in range(target_sum + 1)] for _ in range(n + 1)]
        
        # Call the helper function with initialized memo table
        return self.helper(memo, arr, target_sum, n)

    def equalPartition(self, N, arr):
        total_sum = sum(arr)
        
        # If the total sum is odd, it's not possible to partition
        if total_sum % 2 != 0:
            return 0
        
        # Check if there's a subset with sum equal to total_sum / 2
        target_sum = total_sum // 2
        return 1 if self.isSubsetSum(arr, target_sum, N) else 0