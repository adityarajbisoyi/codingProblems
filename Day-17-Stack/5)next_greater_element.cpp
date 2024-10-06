SOlution 1-:
Steps-:
1)Using same idea as we do in stock span problem.


Code-:
vector<long long> nextLargerElement(vector<long long> arr, int n){
       vector<long long>v;
       stack<int>st;
       st.push(n-1);
       v.push_back(-1);
       for(int i=n-2;i>=0;i--)
       {
           while(st.empty()==false and arr[st.top()]<=arr[i])
           {
               st.pop();
           }
           if(st.empty()==false)
           v.push_back(arr[st.top()]);
           else
           v.push_back(-1);
           
           st.push(i);
       }
       reverse(v.begin(),v.end());
       return v;
    }


Python Code-:
class Solution:
    
    # Function to calculate the span of stock’s price for all n days.
    def calculateSpan(self, a, n):
        # List to store the span for each day
        span = [0] * n
        # Stack to store indices of the days
        st = []
        
        # Span of the first day is always 1
        span[0] = 1
        # Push the index of the first day to the stack
        st.append(0)
        
        # Iterate through the rest of the days
        for i in range(1, n):
            # Pop elements from the stack while it's not empty and
            # the price at the top of the stack is less than or equal to the current day's price
            while st and a[st[-1]] <= a[i]:
                st.pop()
            
            # If the stack is not empty, calculate the span
            if st:
                span[i] = i - st[-1]
            else:
                # If the stack is empty, the span is the number of days so far (i + 1)
                span[i] = i + 1
            
            # Push the current day's index onto the stack
            st.append(i)
        
        return span
