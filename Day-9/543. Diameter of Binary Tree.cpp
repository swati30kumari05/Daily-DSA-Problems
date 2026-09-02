class Solution {
    int ans=0;
    int dfs(TreeNode* r){
        if(!r) return 0;
        int l=dfs(r->left), h=dfs(r->right);
        ans=max(ans,l+h);
        return 1+max(l,h);
    }
public:
    int diameterOfBinaryTree(TreeNode* root){
        dfs(root);
        return ans;
    }
};
