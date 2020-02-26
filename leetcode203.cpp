/*************************************************************************
	> File Name: leetcode203.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 00时57分58秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    	if(!head) return NULL; //先处理头节点情况
    	while(head->val == val){
    		head = head->next;
    		if(!head) return head;
    	}
    struct	ListNode* head_bak = head;
    	while(head_bak->next){
    		if(head_bak->next->val == val){
    			if(!head_bak->next->next) head_bak->next = NULL;
    			else head_bak->next = head_bak->next->next;
    		}else{
    			head_bak = head_bak->next;
    			if(!head_bak) return head;
    		}
    	}
    	return head;
    }

