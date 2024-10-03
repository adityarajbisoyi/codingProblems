Solution 1-:
Steps-:
1)Using level order traversal
2)add when i==size of level of tree  (i==n)

Code-:
void helper(TreeNode* root,vector<int>&v)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(q.empty()==false)
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(i==size-1)
                v.push_back(curr->val);
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        if(root==NULL)
        return v;
        helper(root,v);
        return v;
    }

Python Code-:
class Solution:
    # Function to return a list containing elements of the right view of the binary tree.
    def rightView(self, root):
        result = []  # List to hold the right view elements
        if root is None:
            return result  # Return empty list if the tree is empty

        q = deque()  # Queue for level-order traversal
        q.append(root)

        while q:
            size = len(q)  # Number of nodes at the current level
            
            for i in range(size):
                curr = q.popleft()  # Get the front node
                
                # If it's the last node of the current level, add to the right view
                if i == size - 1:
                    result.append(curr.data)
                
                # Add left and right children to the queue
                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)

        return result  # Return the list containing the right view



Solution 2-:
Steps-:
1)Using same approach as we do in left view just till bit changes  
2)in right view we go to right side first then go to left side but in left view we go to left side then go to 
  right side.
Code-:
oid helper(TreeNode* root,vector<int>&v,int level,int &max_level)
    {
       if(root==NULL)
       return ;
       if(level>max_level)
       {
          v.push_back(root->val);
          max_level=level;
       }

       helper(root->right,v,level+1,max_level);
       helper(root->left,v,level+1,max_level);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        if(root==NULL)
        return v;
        int max_level=0;
        int level=1;
        helper(root,v,level,max_level);
        return v;
    }

