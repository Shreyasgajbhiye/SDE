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
        queue<pair<TreeNode*,unsigned long long >> q;
        q.push({root, 0});
        unsigned long long maxi = 0;
        while(!q.empty()){
            unsigned long long l = q.front().second;
            unsigned long long r = q.back().second;

            maxi = max(maxi, r-l+1);

            unsigned long long sz = q.size();

            for(int i=0;i<sz;i++){
                TreeNode* n = q.front().first;
                unsigned long long idx = q.front().second;
                q.pop();
                if(n->left){
                    q.push({n->left, 2*idx+1});
                }
                if(n->right){
                    q.push({n->right, 2*idx+2});
                }
            }
        }
        return maxi;


//         queue<pair<TreeNode* , long long>> q;
//         q.push({root, 0});
//          long long width = 0;
//         while(!q.empty()){
//              long long l = q.front().second;
//             long long r = q.back().second;
//             width = max(width, r-l+1);
//              long long sz = q.size();
//             for( long long i=0;i<sz;i++){
//                 TreeNode* node = q.front().first;
//                  long long lv = q.front().second;
//                 q.pop();

//                 if(node->left) q.push({node->left, 2*lv+1});
//                 if(node->right) q.push({node->right, 2*lv+2});
//             }
//         }
// return width;
    }
};