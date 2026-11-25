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
    int hight(TreeNode* root){
    if(root == NULL){
        return 0 ;
    }
    int left = hight(root->left);
    int right = hight(root->right);
    return max(left , right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftD = diameterOfBinaryTree(root->left);
        int rightD = diameterOfBinaryTree(root->right);
        int currD = hight(root->left)+ hight(root->right);

        return max(max(leftD, rightD), currD);
    }
};