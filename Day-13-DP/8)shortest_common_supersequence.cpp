int lcs(int n, int m, string s1, string s2)
{
       vector<int>prev(m+1,0);
       vector<int>curr(m+1,0);
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=m;j++)
           {
               if(s1[i-1]==s2[j-1])
               curr[j]=1+prev[j-1];
               else
               curr[j]=max(prev[j],curr[j-1]);
           }
           prev=curr;
       }
       return curr[m];
}

int shortestCommonSupersequence(string X, string Y, int m, int n)
{
       int LCS=lcs(m,n,X,Y);
       int n1=m-LCS;
       int n2=n-LCS;
       return LCS+n1+n2;
}

Python Code-:

class Solution:
    # Function to find length of shortest common supersequence of two strings.
    def lcs(self, n, m, s1, s2):
        # Initialize two arrays to store the previous and current rows of the DP table
        prev = [0] * (m + 1)
        curr = [0] * (m + 1)

        # Fill the DP table for LCS
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if s1[i - 1] == s2[j - 1]:  # Characters match
                    curr[j] = 1 + prev[j - 1]
                else:  # Characters do not match
                    curr[j] = max(prev[j], curr[j - 1])
            # Move current row to previous for the next iteration
            prev = curr[:]
        
        return curr[m]

    def shortestCommonSupersequence(self, X, Y, m, n):
        # Get the length of the longest common subsequence
        LCS = self.lcs(m, n, X, Y)
        # Calculate the length of the shortest common supersequence
        return (m - LCS) + (n - LCS) + LCS