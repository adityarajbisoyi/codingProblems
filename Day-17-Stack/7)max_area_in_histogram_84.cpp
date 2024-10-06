Solution 1-:
Steps-:
1)At current index we find prev_smaller until we add (current+=current_element).
2)At current index we find next_smaller elemnt until we add (current+=current_element).

Code-: Time->O(n2) Space->O(1)
int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int res=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int sum=heights[i];
            int val=heights[i];
            //left side
            for(int j=i-1;j>=0;j--)
            {
                if(heights[j]<val)
                break;
                else
                sum+=val;
            }

            //right side
            for(int j=i+1;j<n;j++)
            {
                if(heights[j]<val)
                break;
                else
                sum+=val;
            }
            res=max(res,sum);
        }
        return res;
    }



Solution 2-:
Steps-:
1)As we understand in sol1 we need prev smaller element and next smaller element but here we change a bit 
2)Here we find the prev smaller index and store into array1 
3)Now we find the next smaller index and store into array2.
4)Now travese the loop and calculate max as -:
   height[i] * (array2[i]-array1[i]-1)



Code-: Time->O(N)  Space->O(2n)  means using 2 stack here.




Solution 3-:
Steps-:
1)here we using one stack while we running the loop at index i if arr[i]<arr[st.top()] means for st.top() 
  index we find the next smaller element index and for prev smaller we find by st.top()
2)If there is stack empty for prev we use i 
3)If there is no element left in next side means we use =>n no. of  elements



Code-: Time->O(N) Space->O(N)
 int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        st.push(0);
        int ans=INT_MIN;

        for(int i=1;i<n;i++)
        {
            while(st.empty()==false and heights[i]<heights[st.top()])
            {
               int index=st.top();
               st.pop();
               int val1=heights[index];
               int val2=(st.empty()==true)?i:(i-st.top()-1);
               int value=val1*val2;
               ans=max(ans,value);
            }
            st.push(i);
            
        }

        while(st.empty()==false)
        {
            int index=st.top();
            st.pop();
            int val=heights[index] * ((st.empty()==false)?(n-st.top()-1):n);
            ans=max(ans,val);
        }
        return ans;
}

  

Python Code-:
class Solution:
    
    # Function to find the largest rectangular area possible in a given histogram.
    def getMaxArea(self, histogram):
        n = len(histogram)
        # Stack to store indices of histogram bars
        st = []
        # Variable to store the maximum area
        max_area = 0
        
        # Iterate through the histogram bars
        for i in range(n):
            # Process the bars in the stack that are greater than the current bar
            while st and histogram[st[-1]] > histogram[i]:
                # Get the height of the bar at the top of the stack
                height = histogram[st.pop()]
                # Determine the width of the rectangle using the current index and the index of the top element in the stack
                width = i if not st else i - st[-1] - 1
                # Calculate the area of the rectangle and update max_area if necessary
                max_area = max(max_area, height * width)
            
            # Push the current bar index onto the stack
            st.append(i)
        
        # Process any remaining bars in the stack
        while st:
            height = histogram[st.pop()]
            width = n if not st else n - st[-1] - 1
            max_area = max(max_area, height * width)
        
        return max_area
