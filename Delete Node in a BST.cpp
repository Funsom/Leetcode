/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;
        if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else{
            if(!root->left||!root->right){
                root=(root->left)?root->left:root->right;
                return root;
            }
            else{
                TreeNode* cur=root->right;
                while(cur->left)cur=cur->left;
                root->val=cur->val;
                root->right=deleteNode(root->right,root->val);
            }
        }
        return root;
    }
};
