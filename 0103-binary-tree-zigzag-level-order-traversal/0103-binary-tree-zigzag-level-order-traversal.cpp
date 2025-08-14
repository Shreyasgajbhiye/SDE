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

        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        int flag = true;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> level(sz);

            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();

                int idx = (flag) ? i : (sz - 1 - i);
                level[idx] = node->val;
                if(node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }
            flag = !flag;
            ans.push_back(level);
        }
        return ans;
    }
};