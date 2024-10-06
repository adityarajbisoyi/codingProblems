Solution 1-:
Steps-:
1)here we use 2 for loops

Code-: Time->O(n2) Space->O(1)
vector <int> calculateSpan(int price[], int n)
{
       vector<int>v;
       v.push_back(1);
       for(int i=1;i<n;i++)
       {
           int j;
           for(j=i-1;j>=0;j--)
           {
               if(price[j]>price[i])
               {
                   v.push_back(i-j);
                   break;
               }
           }
           if(j==-1)
           v.push_back(i+1);
       }
       return v;
}


Solution 2-:
Steps-:
1)here we use stack to store index 
2)there are 3 cases-:
  1. if prev element<=curr element  then pop the index from stack.
  2. if stack is empty means all prev element is smaller than current so its range is [i+1] means current_index+1
  3. else means st.top()>curr element so (v.push_back(curr_index-st.top()))
     at every step we add index into stack/

Code-: Time->O(n) Space->O(N)
vector <int> calculateSpan(int price[], int n)
    {
       vector<int>v;
       v.push_back(1);
       stack<int>st;
       st.push(0);
      
       for(int i=1;i<n;i++)
       {
           while(st.empty()==false and price[st.top()]<=price[i])
           {
               st.pop();
           }
           if(st.empty()==false)
           v.push_back(i-st.top());
           else
           v.push_back(i+1);
           
           st.push(i);
       }
       return v;
    }
    

Python Code-:
class Solution:
    
    # Function to calculate the span of stock’s price for all n days.
    def calculateSpan(self, a, n):
        # List to store the span for each day
        span = []
        # Stack to store indices of the days
        st = []
        
        # Span of the first day is always 1
        span.append(1)
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
                span.append(i - st[-1])
            else:
                # If the stack is empty, the span is the number of days so far (i + 1)
                span.append(i + 1)
            
            # Push the current day's index onto the stack
            st.append(i)
        
        return span
