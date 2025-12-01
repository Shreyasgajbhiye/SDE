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
    bool match(TreeNode* r1, TreeNode* r2){
        if(r1!=NULL && r2!=NULL){
            bool a = match(r1->left, r2->right);
            bool b = match(r1->right, r2->left);

            if((r1->val == r2->val) && a && b){
                return true;
            }
            else{
                return false;
            }
        }
        else if(r1 == NULL && r2==NULL){
                return true;
        }
        else 
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return 
            match(root->left, root->right);
    }
};