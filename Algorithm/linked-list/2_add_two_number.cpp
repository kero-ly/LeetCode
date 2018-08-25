/*  '''
【题目】
给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
'''  */

/*
解法1
思路：计算一次结果，再生成一个新的node赋值
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		
        // 使用new分配一个新的内存，返回的时候可以不因为是临时变量而销毁
        ListNode* chain = new ListNode(0);
        // 另外使用一个链头，在return的时候方便返回
        ListNode* head = chain;
        
        // 进位标识
        int carry = 0;
		
        // 注意是 或 
        while (l1 != NULL || l2 != NULL) {
			
            // 如果是空则赋值0，非空就是当前值
            int val1 = (l1 == NULL) ? 0 : l1->val;
            int val2 = (l2 == NULL) ? 0 : l2->val;
            
            // 这里要先计算下一个节点的值，再计算进位，不然会把当前进位加到当前的值上
            chain->next = new ListNode((val1+val2+carry)%10);
            carry = (val1+val2+carry)/10;
            
            // 链表推进
            chain = chain->next;
            l1 = (l1 == NULL) ? l1 : l1->next;
            l2 = (l2 == NULL) ? l2 : l2->next;
        }
		
        // 别忘了最后可能有最高位的进位
        if (carry > 0)
            chain->next = new ListNode(carry);
		
        // 由于链的第一个节点值初始化是0，后面才开始新建-赋值，因此需要把第0个节点去掉
        return head->next;
    }
};
