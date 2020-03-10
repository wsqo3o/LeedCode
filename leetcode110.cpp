/*************************************************************************
	> File Name: leetcode110.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月10日 星期二 03时06分19秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int Depth(struct TreeNode *root){
    if(root == NULL) return 0;
    int l = Depth(root->left), r = Depth(root->right);
    return (l > r ? l : r) + 1;
}

bool isBalanced(struct TreeNode* root){
    if(root == NULL) return true;
    int l = Depth(root->left), r = Depth(root->right);
    if(abs(l - r) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}
