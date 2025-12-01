/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        if(root == NULL) return v;
        while(!q.empty()){
            int sz = q.size();
            vector<int> temp(sz);
            for(int i=0;i<sz;i++){
                TreeNode* n = q.front();
                q.pop();

                int idx = (flag) ? i : (sz-1-i);
                temp[idx] = n->val;
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
                
            }
            flag = !flag;
            v.push_back(temp);
        }
        return v;
    }
};