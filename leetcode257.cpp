/*************************************************************************
	> File Name: leetcode257.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月10日 星期二 02时55分57秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int getPathCnt(struct TreeNode *root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    return getPathCnt(root->left) + getPathCnt(root->right); 
}

int getResult(struct TreeNode *root, int len, int k, char **ret, char *buff){
    if(root == NULL) return 0;
    len += sprintf(buff + len, "%d", root->val);
    buff[len] = 0;
    if(root->left == NULL && root->right == NULL){
        ret[k] = strdup(buff);
        return 1;
    }
    len += sprintf(buff + len, "->");
    int cnt = getResult(root->left, len, k + cnt, ret, buff);
    cnt += getResult(root->right, len, k + cnt, ret, buff);
    return cnt;
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    int pathCnt = getPathCnt(root);
    char **ret = (char *)malloc(sizeof(char *) * pathCnt);
    int max_len = 1024;
    char *buff = (char *)malloc(sizeof(char) *max_len);
    getResult(root, 0, 0, ret, buff);
    *returnSize = pathCnt;
    return ret;
}
