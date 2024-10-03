Solution 1-:
Steps-:
1)Using heights of max(root->left+root->right),max(fun(root->left),fun(root->right));


Code-: Time->O(n2) Space ->O(1)  there is only space using for recursion
int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int left=height(root->left);
        int right=height(root->right);

        return max(left+right,max(diameterOfBinaryTree(root->left),
                                  diameterOfBinaryTree(root->right)));
}




Solution 2-:
Steps-:
1)here we make res reference variable at last we have to return res
2)from bottom we have to return height and in res we store =>res=(left+right)

Code-: Time->O(n)
int helper(TreeNode* root,int &res)
{
        if(root==NULL) return 0;
        
        int left=helper(root->left,res);
        int right=helper(root->right,res);
        res=max(res,left+right);
        return 1+max(left,right);
}

int diameterOfBinaryTree(TreeNode* root) 
{
        if(root==NULL) return 0;
        int res=0;
        helper(root,res);
        return res;
}

Python Code-:
class Solution:
    dia=0
    
    #Function to find the diameter of a Binary Tree.
    def util(self,root):
        
        #if node becomes null, we return 0.
        if root == None:
            return 0
        global dia
        
        #calling the util function recursively for the left and 
        #right subtrees to find their heights.
        l=self.util(root.left)
        r=self.util(root.right)
        
        #storing the maximum possible value of l+r+1 in diameter.
        dia=max(dia, l+r+1)
        
        #returning height of subtree.
        return 1 + max(l, r)
    
  
    #Function to return the diameter of a Binary Tree.
    def diameter(self,root):
        global dia
        dia=0
        #calling the function to find the result.
        self.util(root)
        #returning the result.
        return dia