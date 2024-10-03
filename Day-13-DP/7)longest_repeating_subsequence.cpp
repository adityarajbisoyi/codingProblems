
int lcs(int n, int m, string s1, string s2)
{
       vector<int>prev(m+1,0);
       vector<int>curr(m+1,0);
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=m;j++)
           {
               if(s1[i-1]==s2[j-1] and i!=j)
               curr[j]=1+prev[j-1];
               else
               curr[j]=max(prev[j],curr[j-1]);
           }
           prev=curr;
       }
       return curr[m];
}
    
int LongestRepeatingSubsequence(string str)
{
		    int n=str.length();
		    return lcs(n,n,str,str);
}

Python Code-:

class Solution:
    def lcs(self, n, m, s1, s2):
        # Initialize two arrays to store the previous and current rows of the DP table
        prev = [0] * (m + 1)
        curr = [0] * (m + 1)
        
        # Fill the DP table
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                # Check if characters match and ensure they are not the same index in both strings
                if s1[i - 1] == s2[j - 1] and i != j:
                    curr[j] = 1 + prev[j - 1]
                else:
                    curr[j] = max(prev[j], curr[j - 1])
            # Move current row to previous for the next iteration
            prev = curr[:]
        
        return curr[m]
    
    def LongestRepeatingSubsequence(self, str):
        n = len(str)
        # Call the lcs function with both strings being the same
        return self.lcs(n, n, str, str)