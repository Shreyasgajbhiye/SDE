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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* , unsigned long long>> q;
        unsigned long long maxi = 0;

        q.push({root, 0});
        while(!q.empty()){
            unsigned long long L = q.front().second;
            unsigned long long R = q.back().second;
            maxi = max(maxi, R-L+1);

            unsigned long long n = q.size();
            while(n--){
                TreeNode* curr = q.front().first;
                unsigned long long idx = q.front().second;
                q.pop();

                if(curr->left){
                    q.push({curr->left, 2*idx+1});
                }

                if(curr->right){
                    q.push({curr->right, 2*idx+2});
                }
            }
        }
        return maxi;
    }
};