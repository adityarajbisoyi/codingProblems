Solution 1-:
Steps-:
1)we are given a bst means its inorder is sorted so we store it into vector v.
2)now traverse the vector v 
  if (v[i]>=input) 
  return v[i];

Code-:
void helper(Node* root,vector<int>&v)
{
    if(root==NULL) return ;
    helper(root->left,v);
    v.push_back(root->data);
    helper(root->right,v);
}
int findCeil(Node* root, int input) {
   vector<int>v;
   helper(root,v);
   
   for(int i=0;i<v.size();i++)
   {
       if(v[i]>=input)
       return v[i];
   }
   return -1;
}


Solution 2-:
Steps-:
Three steps-:
1)if the root->data==input
  return root->data;
  // store the value and go to left side to find smaller value.
2) if (root->data>input)
   {
    res=root->data;
    root=root->left;
   }
   // here curr value is smaller so we have to go to right side.
3) if(root->data<input)
   root=root->right.
   
Code-:
int findCeil(Node* root, int input) {
    int res=-1;
    while(root!=NULL)
    {
        if(root->data==input) return root->data;
        else if(root->data>input) 
        {
            res=root->data;
            root=root->left;
        }
        else
        root=root->right;
    }
    return res;
}


Python Code-:
class Solution:
    # Function to find the ceil value in a BST.
    def findCeil(self, root, inp):
        res = -1  # Initialize result to -1, indicating no ceil found initially
        while root is not None:
            if root.key == inp:
                return root.key  # Exact match found
            elif root.key > inp:
                res = root.key  # Potential ceil value found
                root = root.left  # Move left to find a smaller potential ceil
            else:
                root = root.right  # Move right to find a larger value
        return res  # Return the ceil value or -1 if not found

Java -:
int findCeil(Node root, int key) {
       int res=-1;
       while(root!=null)
       {
           if(root.data==key)
           return root.data;
           else if(root.data>key)
           {
               res=root.data;
               root=root.left;
           }
           else
           root=root.right;
       }
       return res;
}