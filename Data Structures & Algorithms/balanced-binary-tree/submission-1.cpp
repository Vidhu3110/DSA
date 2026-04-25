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
    bool isBalanced(TreeNode* root) {
        return DFS(root)[0] == 1;
    }
    vector<int> DFS(TreeNode* root){

        if(!root){
            return {1,0};
        }
        vector<int> left = DFS(root->left);
        vector<int> right = DFS(root->right);

        int balance = (left[0] == 1 && right[0] == 1) && (abs(left[1]-right[1])<=1);

        int h = 1+max(left[1],right[1]);

        return {balance ? 1 : 0 , h};
    }
};
