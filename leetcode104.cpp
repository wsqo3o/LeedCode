/*************************************************************************
	> File Name: leetcode104.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月10日 星期二 03时08分53秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if(root == NULL) return 0;
    int l = maxDepth(root->left), r = maxDepth(root->right);
    return (l > r ? l : r) + 1;
}
