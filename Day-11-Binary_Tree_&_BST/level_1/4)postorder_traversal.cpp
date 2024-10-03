Postorder->  left,right,root

Solution 1-:
Using recursion

Code-:
void helper(TreeNode* root,vector<int>&v)
{
        if(root==NULL) return ;
        helper(root->left,v);
        helper(root->right,v);
        v.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) 
{
        vector<int>v;
        helper(root,v);
        return v;
}



Python Code-:
def postOrder(root):
    result = []
    
    def helper(node):
        if node is None:
            return
        # Recursively visit the left subtree
        helper(node.left)
        # Recursively visit the right subtree
        helper(node.right)
        # Add root node data (visit the node after its children)
        result.append(node.data)
    
    # Call the helper function to start post-order traversal
    helper(root)
    
    return result
