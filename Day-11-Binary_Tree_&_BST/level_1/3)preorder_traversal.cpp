Preorder->  root,left,right

Solution 1-:
Using Recursive-:

Code-: Time->O(N)
void helper(TreeNode* root,vector<int>&v)
{
        if(root==NULL) return ;
        v.push_back(root->val);
        helper(root->left,v);
        helper(root->right,v);
}
    
vector<int> preorderTraversal(TreeNode* root) 
{
        vector<int>v;
        helper(root,v);
        return v;
}

Python Code-:
def preorder(root):
    result = []
    
    def helper(node):
        if node is None:
            return
        # Visit the root node
        result.append(node.data)
        # Recursively visit the left subtree
        helper(node.left)
        # Recursively visit the right subtree
        helper(node.right)
    
    # Call helper to perform preorder traversal
    helper(root)
    
    return result