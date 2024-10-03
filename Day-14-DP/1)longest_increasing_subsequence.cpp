Solution 1-:
Steps-:
1)Make a temp array by making all value 1 bcz min there will be size 1 of increasing subsequence.
2)Now traverse from i=1  to n and at each point i we have to go to left side till reach 0.
3)If we find the min element to the left side from current element i then update the temp[i] to the possible
  max length.


Code-: Time->O(n2) Space->O(n)
int longestSubsequence(int n, int a[])
{
        int temp[n];
        for(int i=0;i<n;i++)
        {
            temp[i]=1;
        }
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[j]>a[i])
                temp[j]=max(temp[j],1+temp[i]);
                ans=max(ans,temp[j]);
            }
        }
        return ans;
}

Solution 2-:
Steps-:
1)Here we make a vector v where we push all elements in it.
2) if v[i]>v[i-1]  then means current element is greater than the last element of vector so we push into vector.
3)else we add that value in vector just greater or equal than current element.


Code-: Time->O(nlog(n))  Space->O(n)
void helper(vector<int>&v,int val)
{
        int n=v.size();
        int low=0;
        int high=n-1;
        while(low<high)
        {
            int mid=(low+high)/2;
            if(v[mid]>=val)
            high=mid;
            else
            low=mid+1;
        }
        v[low]=val;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        v.push_back(nums[0]);

        for(int i=1;i<n;i++)
        {
            if(nums[i]>v.back())
            v.push_back(nums[i]);
            else
            helper(v,nums[i]);
        }
        return v.size();
}


Python Code-:
class Solution:
    
    # Function to find length of longest increasing subsequence.
    def longestSubsequence(self, n, a):
        # Array to store the current LIS
        lis = []
        
        # Iterate through each element in array `a`
        for num in a:
            # If the current number is greater than the last element in `lis`, append it
            if not lis or num > lis[-1]:
                lis.append(num)
            else:
                # Use binary search to find the position where `num` can replace a number
                low, high = 0, len(lis) - 1
                while low < high:
                    mid = (low + high) // 2
                    if lis[mid] >= num:
                        high = mid
                    else:
                        low = mid + 1
                # Replace the element at the found position with `num`
                lis[low] = num
        
        # The length of `lis` is the length of the longest increasing subsequence
        return len(lis)