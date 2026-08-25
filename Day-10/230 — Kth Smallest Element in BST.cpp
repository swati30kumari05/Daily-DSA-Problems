class Solution {
public:
    int kthSmallest(TreeNode* r,int k){
        stack<TreeNode*> s;
        while(1){
            while(r) s.push(r),r=r->left;
            r=s.top(); s.pop();
            if(--k==0) return r->val;
            r=r->right;
        }
    }
};
