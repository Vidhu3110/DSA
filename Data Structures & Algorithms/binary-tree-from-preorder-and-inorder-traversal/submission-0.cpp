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
    unordered_map<int,int> inOrderMap;
    int preorder_idx = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0 ; i< inorder.size();i++){
            inOrderMap[inorder[i]] = i;
        }

        return build(preorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder,int start , int end){
        if(start > end)
            return nullptr;

        int value = preorder[preorder_idx++];
        TreeNode* root = new TreeNode(value);

        int inorderIdx = inOrderMap[value];

        root->left = build(preorder,start,inorderIdx-1);

        root->right = build(preorder,inorderIdx+1 , end);

        return root;
    }
};
