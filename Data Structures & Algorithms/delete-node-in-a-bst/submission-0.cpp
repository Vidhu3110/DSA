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
    TreeNode* findMin(TreeNode* root){
        TreeNode* curr = root;
        while(curr && curr->left){
            curr = curr->left;
        }
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return root;
        }

        if(key < root->val){
            root->left =  deleteNode(root->left,key);
        }
        else if(key > root->val){
            root->right =  deleteNode(root->right,key);
        }
        else{
            if(root->left == nullptr || root->right == nullptr){
                TreeNode* temp = (root->left != nullptr) ? root->left : root->right;
                delete root;
                return temp;
            }
            TreeNode* minVal = findMin(root->right);
            root->val = minVal->val;
            root->right = deleteNode(root->right,minVal->val);
        }
        return root;
    }
};