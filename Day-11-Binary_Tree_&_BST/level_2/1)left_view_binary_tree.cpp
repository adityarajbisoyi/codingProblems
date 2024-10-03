Solution 1-:

Idea-:
1)Using level order traversal
2)Here we traverse line by line using for loop 
3)Store the node value when i==0

Code-: Time->O(N) Space->O(n)
void helper(Node* root,vector<int>&v)
{
    queue<Node*>q;
    q.push(root);
    while(q.empty()==false)
    {
       int size=q.size();
       for(int i=0;i<size;i++)
       {
           Node* curr=q.front();
           q.pop();
           if(i==0)
           v.push_back(curr->data);
           
           if(curr->left)
           q.push(curr->left);
           if(curr->right)
           q.push(curr->right);
       }
    }
}
vector<int> leftView(Node *root)
{
   vector<int>v;
   if(root==NULL) return v;
   helper(root,v);
   return v;
}

Python Code-:
def LeftView(root):
    result = []  # List to store the left view elements
    if root is None:
        return result  # Return empty list if the tree is empty

    q = deque()  # Queue for level-order traversal
    q.append(root)
    
    while q:
        size = len(q)  # Number of nodes at the current level
        
        for i in range(size):
            curr = q.popleft()  # Get the front node
            
            # If it's the first node of the current level, add to the left view
            if i == 0:
                result.append(curr.data)

            # Add left and right children to the queue
            if curr.left:
                q.append(curr.left)
            if curr.right:
                q.append(curr.right)

    return result  # Return the list containing the left view



    
Solution 2-:
Steps-:
1)Using recursion
2)by using max_level with reference and using level 
  always if(level>max_level) that means that level node is not added into our answer so that that node is 
  on left side oe say left view 

Code-: 
void helper(Node* root,int level,int &max_level,vector<int>&v)
{
    if(root==NULL) return ;
    if(level>max_level)
    {
        v.push_back(root->data);
        max_level=level;
    }
    helper(root->left,level+1,max_level,v);
    helper(root->right,level+1,max_level,v);
}
vector<int> leftView(Node *root)
{
   vector<int>v;
   if(root==NULL) return v;
   int max_level=0;
   int level=1;
   helper(root,level,max_level,v);
   return v;
}