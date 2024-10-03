 Solution 1-:
 Steps-:
 1)s1=A;
 2)s2=reverse(A.begin(),A.end())
 3)find lcs.

int helper(string s1,string s2)
{
        int n=s1.length();
        int m=s2.length();
        
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

int longestPalinSubseq(string A) 
{
        string s=A;
        reverse(A.begin(),A.end());
        
        return helper(s,A);
}


Python Code-:
class Solution:
    def longestPalinSubseq(self, S):
        # Helper function to find the length of the longest common subsequence
        def helper(s1, s2):
            n = len(s1)
            m = len(s2)

            # Initialize previous and current rows for DP
            prev = [0] * (m + 1)
            curr = [0] * (m + 1)

            for i in range(1, n + 1):
                for j in range(1, m + 1):
                    if s1[i - 1] == s2[j - 1]:
                        curr[j] = 1 + prev[j - 1]  # Match case
                    else:
                        curr[j] = max(prev[j], curr[j - 1])  # No match case
                prev = curr[:]  # Update previous row for the next iteration

            return curr[m]  # Return the length of LCS

        # Reverse the string S
        reversed_S = S[::-1]

        # Return the length of the longest palindromic subsequence
        return helper(S, reversed_S)