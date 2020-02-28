/*************************************************************************
	> File Name: leetcode234.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 19时01分39秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//O(n)的时间复杂度 将一条链表复制 反转 和原链表是否相等 相等则是回文
//0(1)的时间复杂度 将链表一分为二 

int get_length(struct ListNode *head){
    int n = 0;
    while(head) n += 1, head = head->next;
    return n;
}

struct ListNode *reverse(struct ListNode *head, int n){
    struct ListNode ret, *p = head, *q;
    while(n--) p = p->next;
    ret.next = NULL;
    while(p){
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}

bool isPalindrome(struct ListNode* head){
    int len = get_length(head);
    struct ListNode *p = head, *q = reverse(head ,(len + 1) / 2);
    while(q){
        if(p->val - q->val) return false;
        p = p->next;
        q = q->next;
    }
    return true;
}
