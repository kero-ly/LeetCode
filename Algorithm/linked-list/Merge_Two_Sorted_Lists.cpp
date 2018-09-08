/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 两两比较，然后小的存，小的往后一个，其他不动
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = new ListNode(0);
        ListNode* q = p;
        while (l1 != NULL && l2 != NULL) { 
            if (l1->val <= l2->val) {
                p->next = new ListNode(l1->val);
                p = p->next;
                l1 = l1->next;
            }
            else {
                p->next = new ListNode(l2->val);
                p = p->next;
                l2 = l2->next;
            }       
        }
        p->next = l1 ? l1 : l2;
        return q->next;
    }
};

// 蠢蠢的，就是先全部拿出来排序，然后存一个新的链表
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        vector<int> hh;
        while (l1 != NULL) {
            hh.push_back(l1->val);
            l1 = l1->next;
        }
         while (l2 != NULL) {
            hh.push_back(l2->val);
            l2 = l2->next;
        }
        sort(hh.begin(), hh.end());
        ListNode* p = new ListNode(0);
        ListNode* q = p;
        for (int i = 0; i < hh.size(); i++) {
            p->next = new ListNode(hh[i]);
            p = p->next;
        }
        return q->next;
    }
};
