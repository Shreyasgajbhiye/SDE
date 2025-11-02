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
        // queue<pair<TreeNode*,unsigned long long >> q;
        // q.push({root, 0});
        // unsigned long long maxi = 0;
        // while(!q.empty()){
        //     unsigned long long l = q.front().second;
        //     unsigned long long r = q.back().second;

        //     maxi = max(maxi, r-l+1);

        //     unsigned long long sz = q.size();

        //     for(int i=0;i<sz;i++){
        //         TreeNode* n = q.front().first;
        //         unsigned long long idx = q.front().second;
        //         q.pop();
        //         if(n->left){
        //             q.push({n->left, 2*idx+1});
        //         }
        //         if(n->right){
        //             q.push({n->right, 2*idx+2});
        //         }
        //     }
        // }
        // return maxi;


        queue<pair<TreeNode*, unsigned long long>> q;
        unsigned long long width = 0;
        q.push({root, 0});
        while(!q.empty()){
            TreeNode* n = q.front().first;
            unsigned long long f = q.front().second;
            unsigned long long b = q.back().second;
            width = max(width, b-f+1);
            unsigned long long size = q.size();
            for(unsigned long long i = 0;i<size;i++){
                TreeNode* n = q.front().first;
                unsigned long long f = q.front().second;
                q.pop();
                if(n->left){
                    q.push({n->left, 2*f+1});
                }
                if(n->right){
                    q.push({n->right,2*f+2} );
                }
            }
        }
        return width;
    }
};