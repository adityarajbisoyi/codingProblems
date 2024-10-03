    Code-:
    int helper(vector<int>nums,int n)
    {
        if(n==1)
        return nums[0];
        int a=0;
        int b=nums[0];
        int c;
        for(int i=2;i<=n;i++)
        {
          int val1=nums[i-1] + a;
          int val2=b;
          c=max(val1,val2);
          a=b;
          b=c;
        }
        return c;
    }
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
        return nums[0];
        if(n==2)
        return max(nums[0],nums[1]);

        vector<int>temp1,temp2;
        for(int i=0;i<n-1;i++)
        {
            temp1.push_back(nums[i]);
        }

        for(int i=1;i<n;i++)
        {
            temp2.push_back(nums[i]);
        }

        int res1=helper(temp1,n-1);
        int res2=helper(temp2,n-1);
        return max(res1,res2);
    }


Python Code-:
class Solution:
    # Helper function to calculate the maximum amount that can be robbed from a linear array
    def helper(self, nums, n):
        if n == 1:
            return nums[0]
        
        a, b = 0, nums[0]
        for i in range(2, n + 1):
            val1 = nums[i - 1] + a
            val2 = b
            c = max(val1, val2)
            a = b
            b = c
        
        return b
    
    def rob(self, nums):
        n = len(nums)
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums[0], nums[1])

        # Prepare temp1 (without the last house) and temp2 (without the first house)
        temp1 = nums[:-1]  # Equivalent to nums[0:n-1]
        temp2 = nums[1:]   # Equivalent to nums[1:n]

        # Calculate the result from both temp arrays
        res1 = self.helper(temp1, n - 1)
        res2 = self.helper(temp2, n - 1)

        # Return the maximum of both cases
        return max(res1, res2)