Solution 1-:
Steps-:
1)Using area of historgram
2)here we calculate -:
  1. ist row as heights in histogram function
  2. 2nd row by adding 1st row values if there is 0 then we added  1st row values.
  so on 


  eg. 
  [1,0,1,0,0]   =>[1,0,1,0,0]     find the area of histogram  which is ->1
  [1,0,1,1,1]   =>[2,0,2,1,1]                                          ->4
  [1,1,1,1,1]   =>[3,1,3,2,2]                                          ->6
  [1,0,0,1,0]   =>[4,0,0,3,0]                                          ->4
                                                    max is 6 
                                                    o/p is 6
 

Code-:
int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            while(st.empty()==false and heights[st.top()]>=heights[i])
            {
               int index=st.top();
               st.pop();
               int val=heights[index]*((st.empty()==true)?i:(i-st.top()-1));
               ans=max(ans,val);
            }
            st.push(i);
        }

        while(st.empty()==false)
        {
            int index=st.top();
            st.pop();
            int val=heights[index]*((st.empty()==false)?(n-1-st.top()):n);
            ans=max(ans,val);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>v(m,0);
        int res=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(matrix[i][j]=='0')
               v[j]=0;
               else
               v[j]=v[j]+(matrix[i][j]-'0');
            }
            res=max(res,largestRectangleArea(v));
        }
        return res;
    }



Python Code-:
class Solution(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if not matrix or not matrix[0]:
            return 0

        n = len(matrix)  # Number of rows
        m = len(matrix[0])  # Number of columns
        heights = [0] * m  # Initialize a heights array for the histogram
        max_area = 0  # Variable to store the maximum area

        for i in range(n):
            for j in range(m):
                # Update the heights array based on the current row
                if matrix[i][j] == '1':
                    heights[j] += 1  # Increment the height if it's a '1'
                else:
                    heights[j] = 0  # Reset the height if it's a '0'

            # Calculate the maximum rectangle area for the current histogram
            max_area = max(max_area, self.largestRectangleArea(heights))

        return max_area

    def largestRectangleArea(self, heights):
        n = len(heights)
        stack = []
        max_area = 0

        for i in range(n):
            while stack and heights[stack[-1]] >= heights[i]:
                h = heights[stack.pop()]
                w = i if not stack else i - stack[-1] - 1
                max_area = max(max_area, h * w)

            stack.append(i)

        while stack:
            h = heights[stack.pop()]
            w = n if not stack else n - stack[-1] - 1
            max_area = max(max_area, h * w)

        return max_area
