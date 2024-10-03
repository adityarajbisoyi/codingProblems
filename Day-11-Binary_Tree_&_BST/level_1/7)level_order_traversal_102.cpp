Solution 1-:

Idea-:
Level order traversal means we have to print all nodes from level wise from left to right.
For that we use queue data struture

Code-:
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v;
        vector<int>ans;
        if(root==NULL)
        return v;
        queue<TreeNode*>q;
        q.push(root);
        while(q.empty()==false)
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                ans.push_back(curr->val);
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
            }
            v.push_back(ans);
            ans.clear();
        }
        return v;
}


Python Code-:
class Solution:
    # Function to return the level order traversal of a tree.
    def levelOrder(self, root):
        result = []
        if root is None:
            return result
        
        q = deque()  # Queue to hold nodes at each level
        q.append(root)
        
        while q:
            size = len(q)
            
            for _ in range(size):
                curr = q.popleft()  # Get the front node
                result.append(curr.data)  # Directly append the value to result
                
                # Add left and right children to the queue
                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)
        
        return result  # Return a flat list of values