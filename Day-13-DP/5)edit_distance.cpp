https://www.geeksforgeeks.org/problems/edit-distance3702/1


s="horse"
t="ros"

Solution 1-:
Steps-:
1)Using recusrion 

Code-:
int helper(string s,string t,int n1,int n2)
{
        if(n1==0)
        return n2;
        if(n2==0)
        return n1;
        
        if(s[n1-1]==t[n2-1])
        return helper(s,t,n1-1,n2-1);
        else
        return 1+min(helper(s,t,n1,n2-1), // insert  
                 min(helper(s,t,n1-1,n2), // delete 
                     helper(s,t,n1-1,n2-1)));// replace 
}

int editDistance(string s, string t) {
     
}


Solution 2-:

Code-:
int helper(int memo[101][101],string s,string t,int n1,int n2)
    {
        if(n1==0)
        return n2;
        if(n2==0)
        return n1;
        if(memo[n1][n2]!=-1)
        return memo[n1][n2];
        
        int res;
        
        if(s[n1-1]==t[n2-1])
        res= helper(memo,s,t,n1-1,n2-1);
        else
        res=1+min(helper(memo,s,t,n1,n2-1),
                 min(helper(memo,s,t,n1-1,n2),
                     helper(memo,s,t,n1-1,n2-1)));
        return memo[n1][n2]=res;
    }
    int editDistance(string s, string t) {
       int n1=s.length();
       int n2=t.length();
       int memo[101][101];
       memset(memo,-1,sizeof(memo));
       return helper(memo,s,t,n1,n2);
    }



Java -:
int helper(int [][]memo,String s,String t,int n1,int n2)
    {
        if(n2==0) return n1;
        if(n1==0) return n2;
        
        if(memo[n1][n2]!=-1) return memo[n1][n2];
        
        int res;
        if(s.charAt(n1-1)==t.charAt(n2-1))
        res= helper(memo,s,t,n1-1,n2-1);
        else
        res= 1+Math.min(helper(memo,s,t,n1,n2-1),Math.min(helper(memo,s,t,n1-1,n2),
                     helper(memo,s,t,n1-1,n2-1)));
        return memo[n1][n2]=res;
    }
    public int editDistance(String s, String t) {
        int n1=s.length();
        int n2=t.length();
        int [][]memo=new int[n1+1][n2+1];
        
        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            {
                memo[i][j]=-1;
            }
        }
        return helper(memo,s,t,n1,n2);
    }



Python Code-:
class Solution:
    def helper(self, memo, s, t, n1, n2):
        # Base cases
        if n1 == 0:
            return n2
        if n2 == 0:
            return n1
        
        # If already calculated, return the stored value
        if memo[n1][n2] != -1:
            return memo[n1][n2]
        
        # If characters match, no change needed
        if s[n1 - 1] == t[n2 - 1]:
            res = self.helper(memo, s, t, n1 - 1, n2 - 1)
        else:
            # Compute minimum operations: insert, delete, or replace
            res = 1 + min(self.helper(memo, s, t, n1, n2 - 1),  # Insert
                          self.helper(memo, s, t, n1 - 1, n2),  # Delete
                          self.helper(memo, s, t, n1 - 1, n2 - 1))  # Replace
        
        # Store the result in memo table
        memo[n1][n2] = res
        return res

    def editDistance(self, str1, str3):
        n1 = len(str1)
        n2 = len(str3)
        # Initialize memo table with -1
        memo = [[-1 for _ in range(n2 + 1)] for _ in range(n1 + 1)]
        return self.helper(memo, str1, str3, n1, n2)